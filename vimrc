" use double quote for comment
set autoindent
set expandtab
set shiftwidth=2
set tabstop=2
set softtabstop=2
syntax on
set showcmd
set incsearch
set hlsearch
set scrolloff=6
colorscheme ron
set ignorecase

map <F4> :call AddCppTitle()<cr>
autocmd BufNewFile,BufRead *.c,*.cpp,*.C,*.h,*.js set cindent
autocmd BufNewFile *c,*.cpp exec ":call AddCppTitle()"
function AddCppTitle()
  call append( 0, "// Tag: ")
  call append( 1,"#include<iostream>")
  call append( 2,"#include<cstdio>")
  call append( 3,"#include<cstdlib>")
  call append( 4,"#include<cstring>")
  call append( 5,"#include<climits>")
  call append( 6,"#include<cmath>")
  call append( 7,"#include<ctime>")
  call append( 8,"#include<vector>")
  call append( 9,"#include<queue>")
  call append(10,"#include<stack>")
  call append(11,"#include<list>")
  call append(12,"#include<set>")
  call append(13,"#include<map>")
  call append(14,"#include<utility>")
  call append(15,"#include<algorithm>")
  call append(16,"using namespace std;")
  call append(17,"")
  call append(18,"#define FOR(i,a,b) for(int i=(a);i<(b);++i)")
  call append(19,"#define FORR(i,a,b) for(int i=(a);i<=(b);++i)")
  call append(20,"#define ROR(i,a,b) for(int i=(a);i>=(b);--i)")
  call append(21,"#define RORR(i,a,b) for(int i=(a);i>(b);--i)")
  call append(22,"#define PQ priority_queue")
  call append(23,"#define VR vector")
  call append(24,"#define MST(a,b) memset(a,b,sizeof(a))")
  call append(25,"#define FGETS(s) fgets(s,sizeof(s),stdin)")
  call append(26,"#define ALL(x) x.begin(),x.end()")
  call append(27,"#define INS(x) inserter(x,x.begin())")
  call append(28,"#define FI first")
  call append(29,"#define SE second")
  call append(30,"#define pb push_back")
  call append(31,"typedef long long LL;")
  call append(32,"typedef long long unsigned LLU;")
  call append(33,"typedef pair<int,int> pii;")
  call append(34,"")
endfunction

autocmd BufNewFile *.sh exec ":call AddShellTitle()"
autocmd BufNewFile *.sh exec ":set noexpandtab"
function AddShellTitle()
  call append(0 ,"#!/bin/bash")
  call append(1 ,"")
endfunction

autocmd BufNewFile,BufRead *.s,*.asm exec ":call SetAsm()"
let g:asmsyntax = 'nasm'  " use nasm syntax for asm file
function SetAsm()
  set noexpandtab
  set shiftwidth=4
  set tabstop=4
  set softtabstop=4
endfunction

autocmd BufNewFile,BufRead makefile,Makefile exec ":call SetMake()"
function SetMake()
  set noexpandtab
  set shiftwidth=4
  set tabstop=4
  set softtabstop=4
endfunction
