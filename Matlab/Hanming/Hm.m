clc;clear all;
K=4;
N=7;
msg=randint(1,K)%%生成随机信息位
[H,G] = hammgen(N-K)%%生成汉明码的生成矩阵和校验矩阵
code=encode(msg,N,K,'linear/binary',G)%%汉明码编码
noise=[0 1 0 1 0 0 0];
code_noise=bitxor(code,noise)
rcv=decode(code_noise,N,K,'linear/binary',G)