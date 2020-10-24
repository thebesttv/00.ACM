// Tag: notag
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<utility>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 120;
int n, m;

void print(unsigned char *v, int n, char *prefix = NULL){
  if(prefix) printf("%s: ",prefix);
  FOR(i,0,n) printf("%02x ", v[i]);
  putchar('\n');
}

struct HDD{
  char file_name[10]; FILE *fp;
  bool valid;
  unsigned int uuid, sequence, blocks;

  void open(int n){
    sprintf(file_name, "%d.dsk",n);
    fp = fopen(file_name, "rb");
    fseek(fp, 0, SEEK_END);
    blocks = ftell(fp) / 8 - 1;
#ifdef DEBUG
    printf("%s size: %u\n",file_name, blocks);
#endif
  }

  void read_iden(unsigned char *v){
    fseek(fp, -8, SEEK_END);
    fread(v, 8, 1, fp);
    if(v[0] == 0 && v[1] == 0xbe && v[2] == 0xef){
      valid = true;
      sequence = v[3];
      uuid = (v[4] << 24) + (v[5] << 16) + (v[6] << 8) + v[7];
    }
  }

  bool read_block(int block, unsigned char *res){
    if(block >= blocks) return false;
    fseek(fp, block * 8, SEEK_SET); unsigned char v[10];
    fread(res, 8, 1, fp);
#ifdef DEBUG
    printf("HDD read block %d: ",block); print(res, 8);
#endif
    return true;
  }

  void close(){
    fclose(fp);
  }
}hdd[MAX];

struct RAID{
  unsigned int uuid, stripe_size, n, cnt;
  bool left, symmetric;
  HDD *hdd[MAX];
  RAID(unsigned int uuid) : uuid(uuid) {
    MST(hdd, 0);
    stripe_size = uuid >> 24;
    n = (uuid >> 16) & 0b11111111;
    left = (uuid & (1 << 15)) == 0;
    symmetric = (uuid & (1 << 14)) == 0;
    cnt = 0;
#ifdef DEBUG
    printf("new RAID uuid: %08x, stripe_size: %u, n: %u, %c %c\n",uuid,stripe_size,n, left ? 'L' : 'R',
        symmetric ? 'S' : 'A');
#endif
  }
  void addHDD(HDD *p){
    ++cnt; hdd[p->sequence] = p;
  }
  bool get(unsigned int block, unsigned char *res){
    int stripe = block / stripe_size;
    int k = stripe / (n-1);
    int p_pos = left ? (n - k%n - 1 + n)%n : k % n;
    int drive = symmetric ? (p_pos + 1 + stripe%(n-1))%n : stripe % (n-1) + (stripe%(n-1) >= p_pos);
#ifdef DEBUG
    printf("RAID: uuid: %x, strip size: %u\n",uuid,stripe_size);
    printf("%2d: k: %d, disk %d, stripe %d, ppos: %d\n",block,k,drive,stripe,p_pos);
#endif
    unsigned int d_block = k * stripe_size + block % stripe_size;
    if(hdd[drive] && hdd[drive]->read_block(d_block, res)){
      return true;
    }

    unsigned char v[MAX][8]; int bad = -1;
    FOR(i,0,n) if(!hdd[i] || !hdd[i]->read_block(d_block, v[i])){
      if(bad == -1) bad = i;
      else return false;
    }
    // bad == drive
#ifdef DEBUG
    printf("  bad: %d\n",bad);
#endif
    FOR(i,0,8) res[i] = 0;
    FOR(i,0,n) if(i != bad)
      FOR(j,0,8) res[j] ^= v[i][j];
    return true;
  }
};
map<unsigned int, RAID*> mp;

int main(void){
  scanf("%d%d",&n,&m);

  unsigned char res[MAX];
  int badCnt = 0;
  FOR(i,0,n){
    hdd[i].open(i);
    hdd[i].read_iden(res);
#ifdef DEBUG
    print(res, 8, hdd[i].file_name);
#endif
    if(hdd[i].valid){
#ifdef DEBUG
      printf("valid! uuid: %08x, sequence: %u\n",hdd[i].uuid,hdd[i].sequence);
#endif
      if(!mp.count(hdd[i].uuid))
        mp[hdd[i].uuid] = new RAID(hdd[i].uuid);
      mp[hdd[i].uuid]->addHDD(hdd + i);
    }else ++badCnt;
  }

  printf("%u %d\n",mp.size(),badCnt);
  FOR(k,0,m){
    unsigned int uuid, n; scanf("%x%u",&uuid,&n);
    if(!mp.count(uuid) || !mp[uuid]->get(n,res)){
      printf("-\n"); continue;
    }

    FOR(i,0,8) printf("%02X",res[i]); putchar('\n');
  }

  FOR(i,0,n) hdd[i].close();
  return 0;
}

