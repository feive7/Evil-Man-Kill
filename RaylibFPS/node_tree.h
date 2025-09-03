struct Node {
    Vector3 point;
    Node* node1;
    Node* node2;
    Node* node3;
};

const int NUM_NODES = 17;
Node nodes[17] = {
	{{-0.000000f, 0.000000f, 14.043895f}, nullptr, nullptr, nullptr},
	{{-11.878796f, 0.000000f, 16.998968f}, nullptr, nullptr, nullptr},
	{{-11.937310f, 0.000000f, 23.494268f}, nullptr, nullptr, nullptr},
	{{-0.526645f, 0.000000f, 27.063759f}, nullptr, nullptr, nullptr},
	{{11.644731f, 0.000000f, 22.382462f}, nullptr, nullptr, nullptr},
	{{11.644731f, 0.000000f, 16.940453f}, nullptr, nullptr, nullptr},
	{{0.606696f, 0.000000f, -13.650666f}, nullptr, nullptr, nullptr},
	{{-11.557282f, 0.000000f, -13.246328f}, nullptr, nullptr, nullptr},
	{{-12.770677f, 0.000000f, -2.123568f}, nullptr, nullptr, nullptr},
	{{1.284452f, 0.000000f, 0.303219f}, nullptr, nullptr, nullptr},
	{{-12.265102f, 0.000000f, -27.301458f}, nullptr, nullptr, nullptr},
	{{-0.940100f, 0.000000f, -27.402573f}, nullptr, nullptr, nullptr},
	{{13.168676f, 0.000000f, -1.666912f}, nullptr, nullptr, nullptr},
	{{16.033632f, 0.000000f, -9.082088f}, nullptr, nullptr, nullptr},
	{{17.129055f, 0.000000f, -17.592693f}, nullptr, nullptr, nullptr},
	{{13.505728f, 0.000000f, -25.344925f}, nullptr, nullptr, nullptr},
	{{4.068236f, 0.000000f, -27.282982f}, nullptr, nullptr, nullptr},
};

void InitNodes() {
	nodes[0].node1 = &nodes[1];
	nodes[0].node2 = &nodes[5];
	nodes[0].node3 = &nodes[9];
	nodes[1].node1 = &nodes[0];
	nodes[1].node2 = &nodes[2];
	nodes[2].node1 = &nodes[1];
	nodes[2].node2 = &nodes[3];
	nodes[3].node1 = &nodes[2];
	nodes[3].node2 = &nodes[4];
	nodes[4].node1 = &nodes[3];
	nodes[4].node2 = &nodes[5];
	nodes[5].node1 = &nodes[4];
	nodes[5].node2 = &nodes[0];
	nodes[6].node1 = &nodes[7];
	nodes[7].node1 = &nodes[6];
	nodes[7].node2 = &nodes[8];
	nodes[7].node3 = &nodes[10];
	nodes[8].node1 = &nodes[7];
	nodes[8].node2 = &nodes[9];
	nodes[9].node1 = &nodes[8];
	nodes[9].node2 = &nodes[0];
	nodes[9].node3 = &nodes[12];
	nodes[10].node1 = &nodes[7];
	nodes[10].node2 = &nodes[11];
	nodes[11].node1 = &nodes[10];
	nodes[11].node2 = &nodes[16];
	nodes[12].node1 = &nodes[9];
	nodes[12].node2 = &nodes[13];
	nodes[13].node1 = &nodes[12];
	nodes[13].node2 = &nodes[14];
	nodes[14].node1 = &nodes[13];
	nodes[14].node2 = &nodes[15];
	nodes[15].node1 = &nodes[14];
	nodes[15].node2 = &nodes[16];
	nodes[16].node1 = &nodes[15];
	nodes[16].node2 = &nodes[11];
}