char* getHint(char* secret, char* guess) {
int* sNew = calloc((strlen(secret)),sizeof(int));
int sSize = strlen(secret);
int* bNew = calloc((strlen(secret)),sizeof(int));
int bull = 0;
int cow = 0;
int cnt = 0;
for (int i = 0; i < sSize; ++i){
if (secret[i] == guess[i]){
bull++;
sNew[i] = -1;
bNew[i] = -1;
cnt++;
}
}
cnt = sSize-cnt;
for (int i = 0;i < strlen(secret); ++i){
if (sNew[i] != -1){
sNew[i] = (int)secret[i]-'0';
bNew[i] = (int)guess[i]-'0';
}
}
int* freqS = calloc(10,sizeof(int));
int* freqG = calloc(10,sizeof(int));
for (int i = 0; i < sSize; ++i){
if (sNew[i] != -1){
freqS[sNew[i]]++;
freqG[bNew[i]]++;
}
}
for (int i = 0; i < 10; ++i){
if (freqS[i] > 0 && freqG[i] > 0){
if (freqS[i] <= freqG[i]){
cow += freqS[i];
}
else {
cow += freqG[i];
}
}
}
char* ans = malloc(10*sizeof(char));
/*ans[1] = 'A';
ans[3] = 'B';
ans[0] = (char)bull;
ans[2] = (char)cow+'0';
ans[4] = '\0';*/
sprintf(ans, "%dA%dB",bull,cow);
return ans;
}