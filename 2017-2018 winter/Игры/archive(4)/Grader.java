import java.util.*;

class Grader {
  static final int SIZE = 8;

  public static void main(String[] args) {
    int[][] a = new int[SIZE][];
    for (int i = 0; i < SIZE; ++i) {
      a[i] = new int[SIZE];
    }
    int[] move = new int[2];

    Solution solution = new Solution();

    Scanner in = new Scanner(System.in);
    while (true) {
      for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
          a[i][j] = in.nextInt();
        }
      }
      int c = in.nextInt();
      if (c == -1) {
        break;
      }
      solution.move(a, c, move);
      System.out.println(String.format("%d %d", move[0], move[1]));
      System.out.flush();
    }
  }
}
