import java.util.Arrays;

    public class Main {

        private static void q1() {
            System.out.println("Question 1");
            System.out.println(A1.calculateSalary(3000, 40, 7, 2));
            System.out.println(A1.calculateSalary(41, 40, 6, 6));
            System.out.println(A1.calculateSalary(5000, 40, 12, 6));
            System.out.println(A1.calculateSalary(5000, 40, 3, 10));
            System.out.println(A1.calculateSalary(5000, 40, 3, 3));


        }

        private static void q2() {
            System.out.println("Question 2");
            System.out.println(A1.oddNumber(12345));
            System.out.println(A1.oddNumber(78864));
            System.out.println(A1.oddNumber(88));

        }

        private static void q3() {
            System.out.println("Question 3");
            System.out.println(A1.sumOfDigits(123));
            System.out.println(A1.sumOfDigits(897));
            System.out.println(A1.sumOfDigits(-5));

        }

        private static void q4() {
            System.out.println("Question 4");
            System.out.println(A1.contains(new int[]{2, 2, 6, 5, 1, 2, 3}, new int[]{6, 5, 1}));
            System.out.println(A1.contains(new int[]{7, 2, 1, 6, 2, 3}, new int[]{2, 1, 2}));
            System.out.println(A1.contains(new int[]{6, 9, 3}, new int[]{6, 9, 3}));
            System.out.println(A1.contains(new int[]{5,3,2,1,1,1,1}, new int[]{1,1,1,1}));


        }

        private static void q5() {
            System.out.println("Question 5");
            int[][] startMatrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
            System.out.println(Arrays.deepToString(A1.flipMatrix(startMatrix, 1)));
            System.out.println(Arrays.deepToString(A1.flipMatrix(startMatrix, 2)));
            System.out.println(Arrays.deepToString(A1.flipMatrix(startMatrix, 3)));
            System.out.println(Arrays.deepToString(A1.flipMatrix(startMatrix, 4)));

        }

        public static void main(String[] args) {
            q1();
            q2();
            q3();
            q4();
            q5();
        }
    }
