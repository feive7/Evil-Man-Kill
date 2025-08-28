struct Node {
    Vector3 point;
    Node* node1;
    Node* node2;
    Node* node3;
};

const int NUM_NODES = 32;
Node nodes[32] = {
	{{1.000000f, 1.000000f, -1.000000f}, nullptr, nullptr, nullptr},
	{{1.000000f, -1.000000f, -1.000000f}, nullptr, nullptr, nullptr},
	{{1.000000f, 1.000000f, 1.000000f}, nullptr, nullptr, nullptr},
	{{1.000000f, -1.000000f, 1.000000f}, nullptr, nullptr, nullptr},
	{{-1.000000f, 1.000000f, -1.000000f}, nullptr, nullptr, nullptr},
	{{-1.000000f, -1.000000f, -1.000000f}, nullptr, nullptr, nullptr},
	{{-1.000000f, 1.000000f, 1.000000f}, nullptr, nullptr, nullptr},
	{{-1.000000f, -1.000000f, 1.000000f}, nullptr, nullptr, nullptr},
	{{81.000000f, 1.000000f, -1.000000f}, nullptr, nullptr, nullptr},
	{{81.000000f, -1.000000f, -1.000000f}, nullptr, nullptr, nullptr},
	{{81.000000f, 1.000000f, 1.000000f}, nullptr, nullptr, nullptr},
	{{81.000000f, -1.000000f, 1.000000f}, nullptr, nullptr, nullptr},
	{{79.000000f, 1.000000f, -1.000000f}, nullptr, nullptr, nullptr},
	{{79.000000f, -1.000000f, -1.000000f}, nullptr, nullptr, nullptr},
	{{79.000000f, 1.000000f, 1.000000f}, nullptr, nullptr, nullptr},
	{{79.000000f, -1.000000f, 1.000000f}, nullptr, nullptr, nullptr},
	{{39.000000f, 1.000000f, 39.000000f}, nullptr, nullptr, nullptr},
	{{39.000000f, -1.000000f, 39.000000f}, nullptr, nullptr, nullptr},
	{{41.000000f, 1.000000f, 39.000000f}, nullptr, nullptr, nullptr},
	{{41.000000f, -1.000000f, 39.000000f}, nullptr, nullptr, nullptr},
	{{39.000000f, 1.000000f, 41.000000f}, nullptr, nullptr, nullptr},
	{{39.000000f, -1.000000f, 41.000000f}, nullptr, nullptr, nullptr},
	{{41.000000f, 1.000000f, 41.000000f}, nullptr, nullptr, nullptr},
	{{41.000000f, -1.000000f, 41.000000f}, nullptr, nullptr, nullptr},
	{{39.000000f, 1.000000f, -41.000000f}, nullptr, nullptr, nullptr},
	{{39.000000f, -1.000000f, -41.000000f}, nullptr, nullptr, nullptr},
	{{41.000000f, 1.000000f, -41.000000f}, nullptr, nullptr, nullptr},
	{{41.000000f, -1.000000f, -41.000000f}, nullptr, nullptr, nullptr},
	{{39.000000f, 1.000000f, -39.000000f}, nullptr, nullptr, nullptr},
	{{39.000000f, -1.000000f, -39.000000f}, nullptr, nullptr, nullptr},
	{{41.000000f, 1.000000f, -39.000000f}, nullptr, nullptr, nullptr},
	{{41.000000f, -1.000000f, -39.000000f}, nullptr, nullptr, nullptr},
};

void InitNodes() {
	nodes[0].node1 = &nodes[2];
	nodes[0].node2 = &nodes[1];
	nodes[0].node3 = &nodes[4];
	nodes[1].node1 = &nodes[0];
	nodes[1].node2 = &nodes[3];
	nodes[1].node3 = &nodes[5];
	nodes[2].node1 = &nodes[0];
	nodes[2].node2 = &nodes[3];
	nodes[2].node3 = &nodes[6];
	nodes[3].node1 = &nodes[1];
	nodes[3].node2 = &nodes[2];
	nodes[3].node3 = &nodes[7];
	nodes[4].node1 = &nodes[6];
	nodes[4].node2 = &nodes[5];
	nodes[4].node3 = &nodes[0];
	nodes[5].node1 = &nodes[7];
	nodes[5].node2 = &nodes[4];
	nodes[5].node3 = &nodes[1];
	nodes[6].node1 = &nodes[2];
	nodes[6].node2 = &nodes[7];
	nodes[6].node3 = &nodes[4];
	nodes[7].node1 = &nodes[3];
	nodes[7].node2 = &nodes[6];
	nodes[7].node3 = &nodes[5];
	nodes[8].node1 = &nodes[10];
	nodes[8].node2 = &nodes[9];
	nodes[8].node3 = &nodes[12];
	nodes[9].node1 = &nodes[8];
	nodes[9].node2 = &nodes[11];
	nodes[9].node3 = &nodes[13];
	nodes[10].node1 = &nodes[8];
	nodes[10].node2 = &nodes[11];
	nodes[10].node3 = &nodes[14];
	nodes[11].node1 = &nodes[9];
	nodes[11].node2 = &nodes[10];
	nodes[11].node3 = &nodes[15];
	nodes[12].node1 = &nodes[14];
	nodes[12].node2 = &nodes[13];
	nodes[12].node3 = &nodes[8];
	nodes[13].node1 = &nodes[15];
	nodes[13].node2 = &nodes[12];
	nodes[13].node3 = &nodes[9];
	nodes[14].node1 = &nodes[10];
	nodes[14].node2 = &nodes[15];
	nodes[14].node3 = &nodes[12];
	nodes[15].node1 = &nodes[11];
	nodes[15].node2 = &nodes[14];
	nodes[15].node3 = &nodes[13];
	nodes[16].node1 = &nodes[18];
	nodes[16].node2 = &nodes[17];
	nodes[16].node3 = &nodes[20];
	nodes[17].node1 = &nodes[16];
	nodes[17].node2 = &nodes[19];
	nodes[17].node3 = &nodes[21];
	nodes[18].node1 = &nodes[16];
	nodes[18].node2 = &nodes[19];
	nodes[18].node3 = &nodes[22];
	nodes[19].node1 = &nodes[17];
	nodes[19].node2 = &nodes[18];
	nodes[19].node3 = &nodes[23];
	nodes[20].node1 = &nodes[22];
	nodes[20].node2 = &nodes[21];
	nodes[20].node3 = &nodes[16];
	nodes[21].node1 = &nodes[23];
	nodes[21].node2 = &nodes[20];
	nodes[21].node3 = &nodes[17];
	nodes[22].node1 = &nodes[18];
	nodes[22].node2 = &nodes[23];
	nodes[22].node3 = &nodes[20];
	nodes[23].node1 = &nodes[19];
	nodes[23].node2 = &nodes[22];
	nodes[23].node3 = &nodes[21];
	nodes[24].node1 = &nodes[26];
	nodes[24].node2 = &nodes[25];
	nodes[24].node3 = &nodes[28];
	nodes[25].node1 = &nodes[24];
	nodes[25].node2 = &nodes[27];
	nodes[25].node3 = &nodes[29];
	nodes[26].node1 = &nodes[24];
	nodes[26].node2 = &nodes[27];
	nodes[26].node3 = &nodes[30];
	nodes[27].node1 = &nodes[25];
	nodes[27].node2 = &nodes[26];
	nodes[27].node3 = &nodes[31];
	nodes[28].node1 = &nodes[30];
	nodes[28].node2 = &nodes[29];
	nodes[28].node3 = &nodes[24];
	nodes[29].node1 = &nodes[31];
	nodes[29].node2 = &nodes[28];
	nodes[29].node3 = &nodes[25];
	nodes[30].node1 = &nodes[26];
	nodes[30].node2 = &nodes[31];
	nodes[30].node3 = &nodes[28];
	nodes[31].node1 = &nodes[27];
	nodes[31].node2 = &nodes[30];
	nodes[31].node3 = &nodes[29];
}