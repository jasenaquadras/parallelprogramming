
import java.util.concurrent.ForkJoinPool;
import java.util.*;

public class ParallelQuick {
    public static void main(String[] args) {
        
	Scanner scan=new Scanner(System.in);
	final int n = scan.nextInt();
        int myList[]=new int[n];

        for (int i=0; i<n; i++){
            myList[i]=scan.nextInt();
           }
			}

        QuickSort quickSort = new QuickSort(myList);

        ForkJoinPool pool = new ForkJoinPool();
		//invoke 
        pool.invoke(quickSort);	
	
    }	
}



import java.util.List;
import java.util.concurrent.RecursiveAction;

public class QuickSort extends RecursiveAction {

    private int dataarray[];
    private int left;
    private int right;

    public QuickSort(int dataarray[]){
        this.dataarray=dataarray;
        this.left = 0;
        this.right = dataarray.length - 1;
    }

    public QuickSort(int dataarray[], int left, int right){
        this.dataarray = dataarray;
        this.left = left;
        this.right = right;
    }

    @Override
    protected void compute() {
        if (left < right){
            int pivotIndex = left + ((right - left)/2);

            pivotIndex = partition(pivotIndex);
            invokeAll(new QuickSort(dataarray, left, pivotIndex-1),
                      new QuickSort(dataarray, pivotIndex+1, right));
        }

    }

    private int partition(int pivotIndex){
        int pivotValue = dataarray[pivotIndex];

        swaparrayelem(pivotIndex, right);

        int storeIndex = left;
        for (int i=left; i<right; i++){
            if (((Integer)dataarray[i]).compareTo(pivotValue) < 0){
                swaparrayelem(i, storeIndex);
                storeIndex++;
            }
        }

        swaparrayelem(storeIndex, right);

        return storeIndex;
    }

    private void swaparrayelem(int i, int j){
        if (i != j){
            int iValue = dataarray[i];

            dataarray[i]=dataarray[j];
            dataarray[j]=iValue;
        }
    }
}
