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

map <F4> :call AddCppHeader()<cr>
autocmd BufNewFile,BufRead *.c,*.cpp,*.C,*.h,*.js set cindent
autocmd BufNewFile *c,*.cpp exec ":call AddCppHeader()"
function AddCppHeader()
  0r ~/.cpp_header            " read header from file
  call cursor(line('$'), 0)   " position cursor to end of file
endfunction

autocmd BufNewFile *.sh exec ":call AddShellHeader()"
autocmd BufNewFile *.sh exec ":set noexpandtab"
function AddShellHeader()
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
