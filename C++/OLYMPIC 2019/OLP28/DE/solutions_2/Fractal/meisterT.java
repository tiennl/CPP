import java.io.*;
import java.util.*;
import java.math.*;
import java.awt.geom.Point2D;

public class meisterT {

	public static final double EPS = 1e-10;

	public static int numPoints;
	public static ArrayList<Point2D.Double> points;
	public static ArrayList<Double> lens;


	public static Point2D.Double recur(double percentage, int depth) {
		// search correct segment
		double sum = 0.0;
		int curSegment = 0;
		while (sum + lens.get(curSegment) < percentage) {
			sum += lens.get(curSegment);
			curSegment++;
		}

		// recompute percentage wrt cur segment
		percentage -= sum;
		percentage /= lens.get(curSegment);

		if (depth == 1) {
			Point2D.Double dist = new Point2D.Double();
			dist.x = points.get(curSegment + 1).x - points.get(curSegment).x;
			dist.y = points.get(curSegment + 1).y - points.get(curSegment).y;
			dist.x = points.get(curSegment).x + dist.x * percentage;
			dist.y = points.get(curSegment).y + dist.y * percentage;
			return dist;
		}

		// get rotation and scale factor
		Point2D.Double oldCoords = new Point2D.Double(points.get(curSegment).x, points.get(curSegment).y);
		Point2D.Double translate = new Point2D.Double(points.get(0).x, points.get(0).y);
		double angle = Math.atan2(points.get(curSegment + 1).y - points.get(curSegment).y, points.get(curSegment + 1).x - points.get(curSegment).x);
		angle -= Math.atan2(points.get(numPoints - 1).y - points.get(0).y, points.get(numPoints - 1).x - points.get(0).x);
		double scale = points.get(curSegment).distance(points.get(curSegment + 1)) / points.get(0).distance(points.get(numPoints - 1));

		boolean ugly = true;
		// translate to origin, rotate and scale, translate back
		for (int i = 0; i < numPoints; i++) {
			points.get(i).x -= translate.x;
			points.get(i).y -= translate.y;
			Point2D.Double tmpPoint = new Point2D.Double(points.get(i).x, points.get(i).y);
			tmpPoint.x = Math.cos(angle) * points.get(i).x - Math.sin(angle) * points.get(i).y;
			tmpPoint.y = Math.sin(angle) * points.get(i).x + Math.cos(angle) * points.get(i).y;
			if (Math.abs(tmpPoint.x) > EPS || Math.abs(tmpPoint.y) > EPS) {
				ugly = false;
			}
			points.get(i).x = oldCoords.x + tmpPoint.x * scale;
			points.get(i).y = oldCoords.y + tmpPoint.y * scale;
		}
		if (ugly) {
			return points.get(0);
		}

		return recur(percentage, depth - 1);
	}

	public static void main(String args[]) {
		Locale.setDefault(Locale.US);
		Scanner sc = new Scanner(System.in);

		int numCases = sc.nextInt();

		while (numCases > 0) {
			--numCases;

			numPoints = sc.nextInt();
			points = new ArrayList<Point2D.Double>();
			lens = new ArrayList<Double>();

			double total = 0.0;
			for (int i = 0; i < numPoints; i++) {
				Point2D.Double tmp = new Point2D.Double();

				tmp.x = (double) sc.nextInt();
				tmp.y = (double) sc.nextInt();
				points.add(tmp);
				if (i > 0) {
					double tmpLen = points.get(i).distance(points.get(i - 1));
					lens.add(tmpLen);
					total += tmpLen;
				}
			}
			for (int i = 0; i < numPoints - 1; i++) {
				lens.set(i, lens.get(i) / total);
			}

			int depth = sc.nextInt();
			double fraction = sc.nextDouble();
			Point2D.Double tmp = recur(fraction, depth);
			System.out.printf("(%12.12f,%12.12f)\n", tmp.x, tmp.y);
		}

	}
}

