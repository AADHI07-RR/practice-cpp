
import java.util.*;

class disjoint{
    
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        // Map<Integer,Integer> a=new HashMap<>();
        // for(int i=0;i<n;i++){
        //     a.put(sc.nextInt(),sc.nextInt());
        // }
        int[] leader=new int[n+1];
        for(int i=1;i<=n;i++){
            leader[i]=i;
        }
        for(int i=1;i<=m;i++){
            int lt,rt; 
            lt=sc.nextInt();
            rt=sc.nextInt();
            join(leader,lt,rt);

        }
        Set<Integer> st=new HashSet<>();
        for(int i=1;i<=n;i++)
        {
            st.add(find(leader,i));
        }
        System.out.print(st);
        System.out.print(st.size());


    }

    private static int find(int[] leader, int i) {
        if(leader[i]!=i){
            leader[i]=find(leader,leader[i]);
        }
        return leader[i];
    }
    private static void join(int[] leader, int lt, int rt) {
        int lelt=find(leader,lt);
        int lert=find(leader,rt);
        leader[lert]=lelt;
    }

    
}

// 10 7
// 1 7
// 2 6
// 6 7
// 7 9
// 9 10
// 4 8
// 8 5
