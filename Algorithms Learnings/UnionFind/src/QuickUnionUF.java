/*
  Find or isConnected Complexity -- O(n)
  Union Complexity -- O(n)
*/


public class QuickUnionUF {
	
private int id[];
	
	public QuickUnionUF(int n)
	{
		id = new int[n];
		for(int i = 0;i < n;i++)
			id[i] = i;
	}
	
	private int getRoot(int i)
	{
		while(id[i]!=i)
		{
			i = id[i];
		}
		return i;
	}
	
	public boolean isConnected(int p,int q){
		return getRoot(p) == getRoot(q);
	}
	
	public void union(int p,int q){
		int firstRoot  = getRoot(p);
		int secondRoot = getRoot(q);
		id[firstRoot] = secondRoot;
    }
	
	public void printAfterOperations()
	{
		for(int i = 0;i < id.length;i++)
			System.out.print(id[i] + " ");
	}
	

}
