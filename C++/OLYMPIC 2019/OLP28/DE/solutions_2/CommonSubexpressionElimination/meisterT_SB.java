import java.io.*;
import java.util.*;
import java.math.*;

class Tree {
	int left, right;
	int value;
	int index;
	long hash;
}

public class meisterT_SB {

	public static final int MAX = 50000;
	public static final int NOTREE = 0;

	public static String buffer;

	public static Tree trees[] = new Tree[MAX * 2];
	public static HashMap<Long, ArrayList<Integer>> subTrees;

	public static int numTrees;
	public static int curStringPtr, globalCount;

	public static StringBuilder output;

	public static boolean compare(int first, int second) {
		if (first == second) {
			return true;
		}
		if (first == NOTREE || second == NOTREE) {
			return false;
		}
		if (trees[first].value < 0) {
			return compare(-trees[first].value, second);
		}
		if (trees[second].value < 0) {
			return compare(first, -trees[second].value);
		}

		if (trees[first].value != trees[second].value) {
			return false;
		}

		if (!compare(trees[first].left, trees[second].left)) {
			return false;
		}

		if (!compare(trees[first].right, trees[second].right)) {
			return false;
		}

		return true;
	}

	public static int getTree() {
		int actTree = numTrees;
		numTrees++;

		trees[actTree] = new Tree();

		trees[actTree].value = 0;
		while ('a' <= buffer.charAt(curStringPtr) && buffer.charAt(curStringPtr) <= 'z') {
			trees[actTree].value = trees[actTree].value * 27 + (buffer.charAt(curStringPtr) - 'a' + 1);
			curStringPtr++;
		}

		if (buffer.charAt(curStringPtr) == '(') {
			curStringPtr++; // skip (
			trees[actTree].left = getTree();
			curStringPtr++; // skip ,
			trees[actTree].right = getTree();
			curStringPtr++; // skip )
		} else {
			trees[actTree].left = trees[actTree].right = NOTREE;
		}

		trees[actTree].hash = trees[actTree].value + 2 * trees[trees[actTree].left].hash + 3 * trees[trees[actTree].right].hash;
		boolean duplicate = false;
		ArrayList<Integer> tmpList = subTrees.get(trees[actTree].hash);
		if (tmpList != null) {
			for (Integer index : tmpList) {
				if (compare(actTree, index)) {
					duplicate = true;
					trees[actTree].value = -(index);
					break;
				}
			}
		}

		if (!duplicate) {
			if (tmpList == null) {
				tmpList = new ArrayList<Integer>();
				subTrees.put(trees[actTree].hash, tmpList);	
			}
			tmpList.add(actTree);
		}

		return actTree;
	}

	public static void printTree(int actTree) {
		if (trees[actTree].value < 0) {
			output.append(trees[-trees[actTree].value].index);
			return;
		}
		trees[actTree].index = globalCount;
		globalCount++;

		char val[] = new char[5];
		int valLen = 0;
		while (trees[actTree].value > 0) {
			val[valLen] = (char) ('a' - 1 + (trees[actTree].value % 27));
			valLen++;
			trees[actTree].value /= 27;
		}
		for (int i = valLen - 1; i >= 0; i--) {
			output.append((char) val[i]);
		}
		if (trees[actTree].left == NOTREE) {
			return;
		}
		output.append("(");
		printTree(trees[actTree].left);
		output.append(",");
		printTree(trees[actTree].right);
		output.append(")");
	}

	public static void main(String args[]) {
		Locale.setDefault(Locale.US);
		Scanner sc = new Scanner(System.in);		

		int numCases = sc.nextInt();

		while (numCases > 0) {
			--numCases;

			subTrees = new HashMap<Long, ArrayList<Integer>>();

			buffer = sc.next() + "\0";
			trees[0] = new Tree();
			numTrees = 1;
			curStringPtr = 0;
			int root = getTree();
			globalCount = 1;
			
			output = new StringBuilder();
			printTree(root);
			System.out.println(output);
		}
	}
}
