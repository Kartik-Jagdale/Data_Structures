#include<stdio.h>
#include<assert.h>

//structure define for Set
typedef struct{
  int size;
  int a[20000];
}Set;

//define structure for searchresult
typedef struct{
  int found;
  int val;
}SearchResult;

//index to number
int indnum(int ind)
{
  return ind-10000;
}

//return length of set
int length(Set S)
{
  return S.size;
}

//building an empty set
Set buildempty()
{
  Set S;
  int i=0;
  while(i<20000)
    {
      S.a[i]=0;
      i++;
    }
  S.size=0;
  return S;
}

//putting value in set if does not exit in set
Set put(int x,Set S)
{
  if(S.a[x+10000]==0)
    {
      S.a[x+10000]=1;
    }
  return S;
}

//set build by putting values
Set buildSet(int a[],int n)
{
  Set S = buildempty();
  int i=0;
  while(i<n)
    {
      S=put(a[i],S);
	  i++;
    }
  return S;
}


//for removing the element from the set
Set rem(int x,Set S)
{
  if(S.a[x+10000]==1)
    {
      S.a[x+10000]=0;
    }
  return S;
}

//searching an element
SearchResult Search(int x, Set S)
{
  SearchResult R;
  R.found=0;
  if(S.a[x+10000]==1)
    {
      R.found=1;
      R.val=x;
    }
  return R;
}

//for finding next element of given element 
SearchResult next(int x, Set S)
{
	SearchResult R;
	R.found = 0;
	SearchResult m = Search(x,S);
	if(m.found==1)
	{
	int i=1;
	while(S.a[x+10000+i]==0 && x+10000+i<20000)
	{
	i=i+1;
	}
	if(S.a[x+10000+i]==1)
	{
	R.found=1;
	R.val=x+i;
	}
    }
    return R;
}


//for finding previous element of given element 
SearchResult previous(int x, Set S)
{
	SearchResult R;
	R.found = 0;
	SearchResult m = Search(x,S);
	if(m.found==1)
	{
	int i=1;
	while(S.a[x+10000-i]==0 && x+10000-i>0)
	{
	i=i+1;
	}
	if(S.a[x+10000-i]==1){
	R.found=1;
    R.val=x-i;
    }
    }
    return R;
}


//seraching first element in set 
SearchResult first(Set S)
{
  SearchResult R;
  R.found = 0;
  int i=0;
  while(S.a[i]!=1 && i<20000)
    {
      i=i+1;
    }
  if(S.a[i]==1)
    {
      R.found = 1;
      R.val = i;
    }
  return R;
}
  
//seraching last element in set 
SearchResult last(Set S)
{
  SearchResult R;
  R.found = 0;
   int i=20000;
  while(S.a[i]!=1 && i>=0)
    {
      i=i-1;
    }
  if(S.a[i]==1)
    {
      R.found = 1;
      R.val = i;
    }
  return R;
}
  
//test cases
void testput()
{
	
	Set S = buildempty();
	int i=-10000;
	while(i<10000)
	{	
		S = put(i,S);
		assert(S.a[i+10000] == 1);
		i = i+1;
	}
}

void testrem()
{	
    Set s;
	int a[20000];
    int	i=-10000;
	while(i<10000)
	{
		a[i+10000]=i;
		i=i+1;
	}
    Set S = buildSet(a,20000);
	int x=-10000;
	while(x<10000)
	{
	S = rem(x,S);
	assert(S.a[x+10000] == 0);
	x = x+1;
	}
}

void testbs()
{
	Set s;
	int a[20000];
    int	i=-10000;
	while(i<10000)
	{
		a[i+10000]=i;
		i=i+1;
	}
    s=buildSet(a,20000);
	i=0;
	while(i<20000)
	{
		assert(s.a[i] == 1);
		i=i+1;
	}
}
	
void testnext()
{
	Set S = buildempty();
	int a[20000];
	int	i=-10000;
	while(i<10000)
	{
		a[i+10000]=i;
		i=i+1;
	}
	S=buildSet(a,20000);
	
	i =-10000;
	while(i<9999) 
	{
	SearchResult w = next(i,S);
	assert(S.a[i+10000] == 1);
	i = i+1;
	}
}

void testprevious()
{
	Set S = buildempty();
	int a[20000];
	int	i=-10000;
	while(i<10000)
	{
		a[i+10000]=i;
		i=i+1;
	}
	S=buildSet(a,20000);
	
	i = 9999;
	while(i>-10000) 
	{
	SearchResult w = previous(i,S);
	assert(S.a[i+10000] == 1);
	i = i-1;
	}
}
	

int main()
{

testnext();
/*
  int n;
  scanf("%d",&n);
  int a[n];
  int i=0;
  while(i<n)
    {
      scanf("%d",&a[i]);
      i++;
    }
  Set S;
  S=rem(4,S);
  
  printSet(S);*/
  return 0;
}
