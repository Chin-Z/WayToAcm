#include <cstdio>

#define MAXSIZE 100000

struct stack
{
	int stack[MAXSIZE];
	int head;

	int size() {
		return head+1;
	}

	bool empty() {
		if(head == -1) {
			return true;
		}else return false;
	}

	int top() {
		if(head != -1)
		return stack[head];
	}

	bool push(int k) {
		if(head == MAXSIZE) return false;
		else {
			stack[++head] = k;
			return true;
		}
	}

	bool pop() {
		if(!empty()) {
			head--;
			return true;
		}else return false;
	}

	void clear() {
		head = -1;
	}
};

int main() {
	stack s;
	s.clear();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int o;
		scanf("%d", &o);
		if(o==1) {
			int k;
			scanf("%d", &k);
			s.push(k);
		}else if(o==2) {
			s.pop();
		}else if(o==3){
			printf("%d\n", s.top());
		}
	}
}