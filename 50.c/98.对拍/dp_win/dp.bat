@echo off
:again
dp.input.exe > in
dp.ori.exe < in > dp.out.ori
dp.test.exe < in > dp.out.test
fc /w dp.out.ori dp.out.test > nul
                                    ::要输入到nul
if not errorlevel 1 (
                        ::语句组使用圆括号，注释使用两个冒号
  echo AC
  goto again
) else (
  echo WA
  echo ***dp.out.ori***
  type dp.out.ori
  echo ***dp.out.test***
  type dp.out.test
  pause
)

