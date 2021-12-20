---
title: 'KMP学习笔记'
date:  2018-01-25 10:20
tags:
  - KMP
  - 学习笔记
---


# next 数组

> The length of the longest proper prefix in the (sub)pattern that matches a proper suffix in the same (sub)pattern.

# next 数组与循环节

在 next 数组（P）中，若有 P[i]!=0 && i%(i-P[i])==0 ，则在 B[1:i] 中存在长度 len = i-P[i] 的循环节 B[1:len] ，其循环次数 k = i/len 。

## 举例

对于串 B="AABAABAABAAB" ，有
```
      1 2 3 4 5 6 7 8 9 0 1 2
B[] = A A B A A B A A B A A B
P[] = 0 1 0 1 2 3 4 5 6 7 8 9
```

由 P[12]=9 得 B[1:9] = B[4:12]，也就有
　B[1] = B[4]
　B[2] = B[5]
　B[3] = B[6]
　B[4] = B[7]
　B[5] = B[8]
　B[6] = B[9]
　B[7] = B[10]
　B[8] = B[11]
　B[9] = B[12]

整理可得
　B[1] = B[4] = B[7] = B[10]
　B[2] = B[5] = B[8] = B[11]
　B[3] = B[6] = B[9] = B[12]

　=> B[1:3] = B[4:6] = B[7:9] = B[10:12]

即可得到循环节。

而若 P[13]=9，则有
　B[1:9] = B[5:13] => len=5-1=4
　　B[1] = B[5]
　　B[2] = B[6]
　　...
　　B[5] = B[9]
　　=> B[1] = B[5] = B[9] ...
循环节即为 B[1:4] 。
