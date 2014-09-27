#include <cstdio>

#define MAXSIZE 100000

template <class T>
struct queue
{
	T queue[MAXSIZE];
	int f , rear;

	void init() {
		f=0;
		rear=0;
	}

	bool push(T x) {
		if(!full() && (rear != (rear+1)%MAXSIZE)) {
			queue[rear] = x;
			rear++;
			return true;	
		}
		return false;
	}

	bool pop() {
		if(!empty()) {
			f++;
			return true;
		}
		return false;
	}

	T front() {
		return queue[f];
	}

	T back() {
		return queue[rear];
	}

	bool empty() {
		return f == rear;
	}

	bool full() {
		return (MAXSIZE+(rear - f))%MAXSIZE == MAXSIZE - 1;
	}

	int size() {
		return rear - f;
	}
};

int main() {
	queue<int> q;
	q.init();
	int n;
	scanf("%d", &n);
	while(n--){
		int o;
		scanf("%d", &o);
		if(o==1){
			int k;
			scanf("%d", &k);
			q.push(k);
		}else if(o==2/*&&!q.empty()*/){
			q.pop();
		}else /*if(q.empty()){
			printf("impossible!");
			return 0;
		}else */if(o==3){
			printf("%d\n", q.front());
		}
	}
	return 0;
}
