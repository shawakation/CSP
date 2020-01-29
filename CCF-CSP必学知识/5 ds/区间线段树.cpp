#define maxn 10000
int arr[maxn];
struct node {
	int left,right,val,add;
	node():left(0),right(0),val(0),add(0) {}
	node(int l,int r,int v):left(l),right(r),val(v),add(0) {}
};
node tree[maxn];
void build(int v,int l,int r)  //normally v==1
{
	tree[v].left=l;
	tree[v].right=r;
	if(l==r) {
		tree[v].val=arr[r];
		return;
	}
	int mid=(l+r)/2;
	build(v*2,l,mid);
	build(v*2+1,mid+1,r);
	tree[v].val=tree[v*2].val+tree[v*2+1].val;
}
void update(int v,int l,int r,int m)		//normally v==1
{
	if(tree[v].left==l&&tree[v].right==r) {
		tree[v].val+=m*(r-l+1);
		tree[v].add+=m;
		return;
	}
	if(tree[v].add) {
		tree[v*2].add+=tree[v].add;
		tree[v*2+1].add+=tree[v].add;
		tree[v].add=0;
	}
	int mid=(tree[v].left+tree[v].right)/2;
	if(r<=mid) update(v*2,l,r,m);
	else if(l>mid) update(v*2+1,l,r,m);
	else {
		update(v*2,l,mid,m);
		update(v*2+1,mid+1,r,m);
	}
}
int ans=0;
void query(int v,int l,int r)		//normally v==1
{
	if(tree[v].left==l&&tree[v].right==r) {
		ans+=tree[v].val;
		return;
	}
	if(tree[v].add) {
		tree[v*2].add+=tree[v].add;
		tree[v*2+1].add+=tree[v].add;
		tree[v].add=0;
	}
	int mid=(tree[v].left+tree[v].right)/2;
	if(r<=mid) query(v*2,l,r);
	else if(l>mid) query(v*2+1,l,r);
	else {
		query(v*2,l,mid);
		query(v*2+1,mid+1,r);
	}
}

