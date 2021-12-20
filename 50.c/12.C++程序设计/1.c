Complex & operator = (string s){
  char str[100]; memset(str,0,sizeof(str));
  for(int i_=0;i_<s.length();i_++) str[i_]=s[i_];
  char *p = strtok(str,"+i");
  r=atof(p);
  p=strtok(NULL,"+i");
  i=atof(p);
  return *this;
}
