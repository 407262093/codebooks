const int maxn = ;
int arr[maxn];
int prime[maxn];
void init(){
	for (int i = 0; i < maxn; ++i){
		arr[i] = 0;
	}
}
void find(){
	int num = 0;
	for(int i = 2;i<maxn;i++){
		if(arr[i] == 0){
			prime[num] = 0;
			num++;
			for(int j = i*i;j<maxn;j+=i){
				arr[j] = 1;
			}
		}
	}
}