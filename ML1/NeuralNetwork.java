import java.util.Scanner;

public class NeuralNetwork {

    private int[] layers;
    private double[][][] weights;

    public NeuralNetwork() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of layers: ");
        int numLayers = sc.nextInt();
        layers = new int[numLayers];

        // Getting the number of nodes for every layer
        for (int i = 0; i < numLayers; i++) {
            System.out.print("Enter the number of nodes in the layer " + (i + 1) + ": ");
            layers[i] = sc.nextInt();
        }

        weights = new double[numLayers][][];

        for (int i = 0; i < numLayers; i++) {
            if (i > 0) {
                weights[i] = new double[layers[i]][layers[i - 1]];
                for (int j = 0; j < layers[i]; j++) {
                    for (int k = 0; k < layers[i - 1]; k++) {
                        System.out.print("Enter the weight for edge from node " + (k + 1) + " in layer " + i
                                + " to node " + (j + 1) + " in layer " + (i + 1) + ": ");
                        weights[i][j][k] = sc.nextDouble();
                    }
                }
            }
        }

        sc.close();
    }

    public double getWeight(int layer, int fromNode, int toNode) {
        return weights[layer][toNode - 1][fromNode - 1];
    }

    public static void main(String[] args) {
        // Creating a NeuralNetwork object
        NeuralNetwork nn = new NeuralNetwork();

        // To query the weight of an edge
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the layer of the edge: ");
        int layer = sc.nextInt();
        System.out.print("Enter the source node of the edge: ");
        int sourceNode = sc.nextInt();
        System.out.print("Enter the destination node of the edge: ");
        int destNode = sc.nextInt();

        double weight = nn.getWeight(layer, sourceNode, destNode);
        System.out.println("Weight of the edge: " + weight);

        sc.close();
    }
}

