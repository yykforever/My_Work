/*
  Find or isConnected Complexity -- O(logn)
  Union Complexity -- O(logn)
*/

public class WeightedQuickUnionUF {

   private int id[];
   private int size[];

   public WeightedQuickUnionUF(int n) {
		// TODO Auto-generated constructor stub
		id = new int[n];
		size = new int[n];
		for(int i = 0;i < n;i++)
		{
			id[i] = i;
			size[i] = 1;
		}
   }
   
   private int getRoot(int i){
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
		
		if(firstRoot == secondRoot)
			return;
		
		if(size[firstRoot] >= size[secondRoot]){
		id[secondRoot] = firstRoot;
		size[firstRoot] += size[secondRoot];
		}
		else{
		id[firstRoot] = secondRoot;
		size[secondRoot] += size[firstRoot];
		}
		
   }
	
   public void printAfterOperations()
   {
		for(int i = 0;i < id.length;i++)
			System.out.print(id[i] + " ");
   }
   
   private int getSize(int i)
   {
	   return size[i];
   }
	
}
