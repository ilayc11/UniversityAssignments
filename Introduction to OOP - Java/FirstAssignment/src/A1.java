package assignment1;
public class A1 {
    public static double calculateSalary(int wage, int extraWage, int extraHours, int numOfDeals) {
        //checking if the arguments are good
        if(wage<0||extraWage<0||extraHours<0||numOfDeals<0)
            return 0;
        double salary=0;
        //following the questions conditions
        if(numOfDeals<=4)
          salary=wage+extraWage*extraHours;
        if(numOfDeals>=5 && numOfDeals<=7)
          if(extraHours<10)
              salary=wage*1.05+extraWage*extraHours;
            else
                salary=wage*1.10+extraWage*extraHours;
        if(numOfDeals>7)
          if(extraHours<5)
              salary=wage+numOfDeals*0.02*wage+extraWage*extraHours;
          else
              salary=wage+numOfDeals*0.03*wage+extraWage*extraHours;
    return salary;
    }

    public static int oddNumber(int num) {
        if(num==0)
            return 0;
        //calculating the number using powers of ten
        int tens=1;
        int number=0;
        while(num>0) {
            if ((num % 10) % 2 == 1) {
                number = number + (num % 10) * tens;
                tens*=10;

            }
            num/=10;
        }
        return number;
    }

    public static int sumOfDigits(int num) {
        if(num<0)
            return -1;
        if (num < 10) {
            return num;
        }
        else {
            int sum = 0;
            //using a second recursive function the make sumOfDigits Pure Recursion
            sum=sum2(num);
            return sumOfDigits(sum);
        }
    }
    public static int sum2(int num){
        //calculates the sum of the digits
        if(num==0)
            return 0;
        return num%10+sum2(num/10);
    }


    public static int contains(int[] arr1, int[] arr2) {
        //checking if the conditions are good
        if(arr2==null||arr2.length == 0)
            return 0;
        if(arr1==null||arr1.length==0||arr2.length>arr1.length)
            return -1;
        boolean flag;
        //using arr1[i+j] each time to check number by number, using breaks and inner loops
        for (int i = 0; i <= arr1.length - arr2.length; i++) {
                flag = true;
            for (int j = 0; j < arr2.length; j++) {
                if (arr1[i + j] != arr2[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i;
            }
        }
        return -1;
    }
    public static int[][] flipMatrix(int[][] arr, int option) {
        if(arr==null)
            return null;
        int [][]arr2=new int[arr.length][arr[0].length];
        if(arr[0].length==0)
            return arr2;
        int r=0,c=0;
        //using the naive solution of looping on each cell in arr and putting it in its right place in arr2
        if(option==1) {
            c = arr.length-1;
            for (int i = 0; i < arr.length; i++) {
                r = 0;
                for (int j = 0; j < arr.length; j++) {
                    arr2[r][c] = arr[i][j];
                    r++;
                }
                c--;
            }
            return arr2;
        }
        if(option==2) {
            for (int i = 0; i < arr.length; i++) {
                r = arr.length - 1;
                for (int j = 0; j < arr.length; j++) {
                    arr2[r][c] = arr[i][j];
                    r--;
                }
                c++;
            }
            return arr2;

        }
        if(option==3) {
            r = arr.length - 1;
            for (int i = 0; i < arr.length; i++) {
                c = 0;
                for (int j = 0; j < arr.length; j++) {
                    arr2[r][c] = arr[i][j];
                    c++;
                }
                r--;
            }
            return arr2;
        }
        if(option==4){
                for(int i=0;i<arr.length;i++) {
                    c = arr.length-1;
                    for (int j = 0; j < arr.length; j++) {
                        arr2[r][c] = arr[i][j];
                        c--;
                    }
                    r++;
                }

            return arr2;
        }
        return arr2;
    }
}
