import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        List<String> alphabet = new ArrayList<>();
        int s0 = 0;
        int stateCount = 0;
        int Fcount = 0;
        int[] F;
        Integer[][] auto;
        Scanner scn = new Scanner(System.in);


        try (Scanner scnFile = new Scanner(new File("/Users/limestone/Desktop/labSp2/src/file.txt"))) {

            Set<String> A = new HashSet<>();
            A.addAll(Arrays.asList(scnFile.nextLine().split(" ")));
            alphabet.addAll(A);

            stateCount = scnFile.nextInt();

            s0 = scnFile.nextInt();

            Fcount = scnFile.nextInt();
            F = new int[Fcount];
            for (int i = 0; i < Fcount; ++i)
                F[i] = scnFile.nextInt();

            auto = new Integer[stateCount][alphabet.size()];
            for (Integer[] ints : auto) {
                for (Integer i : ints)
                    i = null;
            }
            scnFile.nextLine();
            while (scnFile.hasNext()) {
                String[] arr = (scnFile.nextLine()).split(" ");
                auto[Integer.parseInt(arr[0])][alphabet.indexOf(arr[1])] = Integer.parseInt(arr[2]);
            }
        } catch (FileNotFoundException e) {
            System.out.println("Невдача читання з файлу");
            return;
        }


        System.out.println("Введіть слово w1:");
        String[] w1 = scn.nextLine().split("");

        System.out.println("Введіть слово w2:");
        String[] w2 = scn.nextLine().split("");

        if(!alphabet.containsAll(Arrays.asList(w1))||!alphabet.containsAll(Arrays.asList(w2)))
        {
            System.out.println("Введено слова на недопустимому алфавіті");
            return;
        }

        Integer currentState1 = checkW1(w1,auto,s0,alphabet);
        if (currentState1.equals(-1)) {
                System.out.println("Не розпізнає");
                return;

        }

        List<Integer> finalW2=checkW2(w2,auto,alphabet,stateCount,F);

        boolean det=false;
        for (int f:finalW2)
        if(IsRoute(auto,currentState1,f,new ArrayList<Integer>())) {
            det = true;
            break;
        }

        if(!det){
            System.out.println("Не розпізнає");
            return;
        }

        System.out.println("Розпізнає");

    }

    public static boolean IsRoute(Integer auto[][],int v1,int v2,List<Integer> visited){
        if(v1==v2)
            return true;
        List<Integer> list=new ArrayList();
        for(int i=0;i<auto[v1].length;++i)
            if(auto[v1][i]!=null)
                list.add(auto[v1][i]);
        if(list.contains(v2))
            return true;
        visited.add(v1);
        for (Integer v:list)
            if(!visited.contains(v))
        return IsRoute(auto,v,v2,visited);
        return false;
    }

    public static Integer checkW1(String[] w1,Integer auto[][],int s0,List<String> alphabet){
        Integer currentState = s0;
        for (String el : w1) {
            currentState = auto[currentState][alphabet.indexOf(el)];
            if (currentState == null) {
                return -1;
            }
        }
        return currentState;
    }

    public static List<Integer> checkW2(String[] w2,Integer auto[][],List<String> alphabet,int stateCount,int[] F) {

        //reverse auto
        Integer[][] reverseAuto = new Integer[stateCount][alphabet.size()];
        for (Integer[] ints : reverseAuto) {
            for (Integer i : ints)
                i = null;
        }
        for (int i = 0; i < stateCount; ++i)
            for (int j = 0; j < alphabet.size(); ++j) {
                if (auto[i][j] != null)
                    reverseAuto[auto[i][j]][j] = i;
            }

        //check w2
        List<Integer> finalW2 = new ArrayList<>();
        for (int f : F) {
            Integer currentState2 = f;
            for (int j = w2.length - 1; j >= 0; --j) {
                currentState2 = reverseAuto[currentState2][alphabet.indexOf(w2[j])];
                if (currentState2 == null)
                    break;
            }
            if (currentState2 != null) {
                finalW2.add(currentState2);
            }
        }
        return finalW2;
    }
}

