/*
Testing the implemented Algorithms 
*/
public class Tester {

	public static void main(String args[]){
		
		QuickFindUF QFUF = new QuickFindUF(10);
	    QuickUnionUF QUUF = new QuickUnionUF(10);
	    WeightedQuickUnionUF WQUUF = new WeightedQuickUnionUF(10);
	    
	    //  3-6 3-7 6-0 3-2 4-9 8-2 
	    QFUF.union(3, 6);
		QFUF.union(3, 7);
		QFUF.union(6, 0);
		QFUF.union(3, 2);
		QFUF.union(4, 9);
		QFUF.union(8, 2);
		QFUF.printAfterOperations();
		System.out.println();
	    
		// 3-6 3-7 6-0 3-2 4-9 8-2
		QUUF.union(5, 7);
		QUUF.union(8, 7);
		QUUF.union(0, 9);
		QUUF.union(8, 0);
		QUUF.union(6, 9);
		QUUF.union(2, 1);
		QUUF.printAfterOperations();
		System.out.println();
		
		//6-1 3-1 4-8 5-7 7-4 0-1 3-9 9-2 1-5  
	    WQUUF.union(6, 1);
		WQUUF.union(3, 1);
		WQUUF.union(4, 8);
		WQUUF.union(5, 7);
		WQUUF.union(7, 4);
		WQUUF.union(0, 1);
		WQUUF.union(3, 9);
		WQUUF.union(9, 2);
		WQUUF.union(1, 5);
		WQUUF.printAfterOperations();
		
	}
}
