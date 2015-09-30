/*
  Find or isConnected Complexity -- O(1)
  Union Complexity -- O(n)

*/

public class QuickFindUF {
	
	private int id[];
	
	public QuickFindUF(int n)
	{
		id = new int[n];
		for(int i = 0;i < n;i++)
			id[i] = i;
	}
	
	public boolean isConnected(int p,int q){
		return id[p] == id[q];
	}
	
	public void union(int p,int q){
		
		int firstVal = id[p];
		int secondVal = id[q];
		
		for(int i = 0;i < id.length;i++)
		{
			if(id[i] == firstVal)
				id[i] = secondVal;
		}
		
    }
	
	public void printAfterOperations()
	{
		for(int i = 0;i < id.length;i++)
			System.out.print(id[i] + " ");
	}
	


}
