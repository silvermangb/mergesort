/*
 * main.cpp
 *
 *  Created on: Jan 5, 2015
 *      Author: Greg Silverman
 */


using namespace std;

#include <iostream>

template<typename T>
void
copy_array
  (T* p_a, int p_beg, int p_end, T* p_b)
{
  for(int i=p_beg;i<p_end;++i)
  {
	  p_a[i] = p_b[i];
  }
}

template<typename T>
void
top_down_merge
  (T* p_a, int p_beg, int p_mid, int p_end, T* p_b)
{
  int i0 = p_beg;
  int i1 = p_mid;

  for(int j=p_beg;j<p_end;++j)
  {
	  if((i0<p_mid)&&(i1>=p_end || p_a[i0]<p_a[i1]))
	  {
		  p_b[j] = p_a[i0];
		  ++i0;
	  }
	  else
	  {
		  p_b[j] = p_a[i1];
		  ++i1;
	  }
  }
}

template<typename T>
void
top_down_split_merge
  (T* p_a,int p_beg,int p_end,T* p_b)
{
  if((p_end-p_beg)<2)
  {
	  return;
  }

  int middle = (p_beg+p_end)/2;
  top_down_split_merge(p_a,p_beg,middle,p_b);
  top_down_split_merge(p_a,middle,p_end,p_b);
  top_down_merge(p_a,p_beg,middle,p_end,p_b);
  copy_array(p_a,p_beg,p_end,p_b);
}

template<typename T>
void
top_down_merge_sort
  (T* p_a,T* p_b, int p_n)
{
  top_down_split_merge(p_a,0,p_n,p_b);
}

int
main
  ()
{
	int a[] = {5,4,3,2,1,0};
	int b[] = {0,0,0,0,0,0};
	top_down_merge_sort(&a[0],&b[0],6);
	for(int i=0;i<6;++i)
	{
		cout << a[i] << ", ";
	}
	cout << endl;
	return 0;
}

