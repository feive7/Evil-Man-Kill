struct Node {
    Vector3 point;
    Node* node1;
    Node* node2;
    Node* node3;
};

const int NUM_NODES = 6;
Node nodes[6] = {
	{{-0.000000f, 0.000000f, 14.043895f}, nullptr, nullptr, nullptr},
	{{-11.878796f, 0.000000f, 16.998968f}, nullptr, nullptr, nullptr},
	{{-11.937310f, 0.000000f, 23.494268f}, nullptr, nullptr, nullptr},
	{{-0.526645f, 0.000000f, 27.063759f}, nullptr, nullptr, nullptr},
	{{11.644731f, 0.000000f, 22.382462f}, nullptr, nullptr, nullptr},
	{{11.644731f, 0.000000f, 16.940453f}, nullptr, nullptr, nullptr},
};

void InitNodes() {
	nodes[0].node1 = &nodes[1];
	nodes[0].node2 = &nodes[5];
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
}