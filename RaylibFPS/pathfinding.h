#pragma once
#include <node_tree.cpp>
#include <queue>
#include <unordered_map>

float DistancePointToSegment3D(Vector3 point, Vector3 segStart, Vector3 segEnd) {
	Vector3 segDir = Vector3Subtract(segEnd, segStart);
	Vector3 pointDir = Vector3Subtract(point, segStart);

	float segLengthSq = Vector3DotProduct(segDir, segDir);
	if (segLengthSq == 0.0f) return Vector3Length(pointDir); // segStart == segEnd

	float t = Vector3DotProduct(pointDir, segDir) / segLengthSq;
	if (t < 0.0f) t = 0.0f;
	else if (t > 1.0f) t = 1.0f;

	Vector3 projection = Vector3Add(segStart, Vector3Scale(segDir, t));
	return Vector3Distance(point, projection);
}

#include <unordered_set>
std::unordered_set<Node*> visited;
void recursiveNodeDraw(Node* node, bool first = true) {
	if (first) visited = {};
	if (!node || visited.count(node)) return;  // already visited

	visited.insert(node);

	if (node->node1) {
		DrawLine3D(node->point, node->node1->point, GREEN);
		recursiveNodeDraw(node->node1, false);
	}
	if (node->node2) {
		DrawLine3D(node->point, node->node2->point, GREEN);
		recursiveNodeDraw(node->node2, false);
	}
	if (node->node3) {
		DrawLine3D(node->point, node->node3->point, GREEN);
		recursiveNodeDraw(node->node3, false);
	}
}

bool dfs(Node* current, Node* goal, std::vector<Node*>& path, std::unordered_set<Node*>& visited) {
	if (!current) return false;
	if (visited.count(current)) return false;

	visited.insert(current);
	path.push_back(current);

	if (current == goal) {
		return true; // found!
	}

	// Explore neighbors
	Node* neighbors[3] = { current->node1, current->node2, current->node3 };
	for (Node* next : neighbors) {
		if (next && dfs(next, goal, path, visited)) {
			return true;
		}
	}

	// Backtrack
	path.pop_back();
	return false;
}
std::vector<Node*> bfs(Node* start, Node* goal) {
	if (!start || !goal) return {};

	std::queue<Node*> q;
	std::unordered_map<Node*, Node*> parent; // keep track of how we got to each node

	q.push(start);
	parent[start] = nullptr;

	while (!q.empty()) {
		Node* current = q.front();
		q.pop();

		if (current == goal) {
			// reconstruct path
			std::vector<Node*> path;
			for (Node* n = goal; n != nullptr; n = parent[n]) {
				path.push_back(n);
			}
			std::reverse(path.begin(), path.end());
			return path;
		}

		Node* neighbors[3] = { current->node1, current->node2, current->node3 };
		for (Node* next : neighbors) {
			if (next && parent.find(next) == parent.end()) { // not visited yet
				parent[next] = current;
				q.push(next);
			}
		}
	}

	return {}; // no path found
}
Node* TakePath(Node* node, int turn) {
	switch (turn) {
	case 1: return node->node1;
	case 2: return node->node2;
	case 3: return node->node3;
	}
}
void DrawPath(std::vector<Vector3> path) {
	for (int i = 0; i < path.size() - 1; i++) {
		DrawLine3D(path[i], path[i + 1], RED);
	}
}

Node* FindClosestNode(Vector3 point) {
	float closestDistance = INFINITY;
	Node* closestNode = nullptr;
	for (int i = 0; i < NUM_NODES; i++) {
		float distance = Vector3Distance(point, nodes[i].point);
		if (distance < closestDistance) {
			closestDistance = distance;
			closestNode = &nodes[i];
		}
	}
	if(closestNode == nullptr) {
		printf("Can't find closest node\n");
	}
	return closestNode;
}
Node* GetRandomNextNode(Node* node) {
	if (!node) return nullptr;

	std::vector<Node*> options;

	if (node->node1) options.push_back(node->node1);
	if (node->node2) options.push_back(node->node2);
	if (node->node3) options.push_back(node->node3);

	if (options.empty()) return nullptr;

	int idx = GetRandomValue(0,options.size()-1); // pick random index
	return options[idx];
}