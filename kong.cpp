#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 1010;

char tmp[NN], s[NN], ans[55][55];
int flag[NN];

int main() {
	gets(tmp);
	int space_num = 0;
	
	for(int i = 0, j; tmp[i]; i = j) {
		for(j = i; tmp[j] && (isspace(tmp[i]) == isspace(tmp[j])); j++);
		if(isspace(tmp[i])) {
			space_num++;
			for(int k = i + 1; k < j; k++) flag[k] = 1;
		}
	}
	
	int n = 0;
	for(int i = 0; tmp[i]; i++) if(!flag[i]) {
		tmp[n++] = tmp[i];
	}
	tmp[n] = 0;
	
	if(space_num != 2) puts("invalid input"), exit(0);
	if(!isspace(tmp[1]) || !isspace(tmp[3])) puts("invalid input"), exit(0);
	if(tmp[0] == tmp[2]) puts("invalid input"), exit(0);
	
	char a, b; sscanf(tmp, " %c %c %s", &a, &b, s);
	n = strlen(s);
	
	if(n > 40) {
		puts("word too long"), exit(0);
		return 0;
	}
	
	for(int i = 0; i < n; i++) {
		if(s[i] == a) flag[i] = 1;
		else if(s[i] == b) flag[i] = -1;
		else puts("forbidden letter"), exit(0);
	}
	
	int max_h = 0, h = 0;
	for(int i = 0; i < n; i++) {
		h += flag[i];
		max_h = max(max_h, h);
		if(h < 0) puts("unbalanced word"), exit(0);
	}
	
	if(h) puts("unbalanced word"), exit(0);
	
	for(int i = 1; i <= max_h; i++) {
		for(int j = 0; j < n; j++) ans[i][j] = '*';
	}
	
	h = 0;
	for(int i = 0; i < n; i++) {
		h += flag[i];
		if(i && flag[i - 1] != flag[i]) h -= flag[i];
		if(flag[i] > 0) ans[h][i] = '/';
		else ans[h][i] = '\\';
	}
	
	for(int i = max_h; i; i--) {
		for(int j = 0; j < n; j++) printf("%c", ans[i][j]);
		puts("");
	}
	return 0;
}