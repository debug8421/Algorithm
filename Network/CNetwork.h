#ifndef _NETWORK_H_
#define _NETWORK_H_
template<class vertex, class Compare=less<vertex>>
class CNetwork
{
	typedef map<vertex,list<vertex_weight_pair>,Compare> map_class;
	protected:
//		map_class adjacency_map;
	public:
		bool insert_edge(const vertex& v1, const vertex& v2, double& weight);
		bool insert_edge(const vertex& v1, const vertex& v2);
		bool contains_vertex(const vertex& v);
		bool insert_vertex(const vertex& v);
		bool erase_vertex(const vertex& v);
		unsigned int get_edge_count();
		double get_edge_weight(const vertex& v1, const vertex& v2);
		bool contains_edge(const vertex& v1, const vertex& v2);
		
		CNetwork();
		CNetwork(const CNetwork& other);
		unsigned int size();
		bool empty();
		list<vertex> get_nighbor_list(const vertex& v);
		bool is_connected;
		CNetwork<vertex> get_minimum_spanning_tree();
		pair<list<vertex>,double> get_shortest_path(const vertex& v1, const vertex& v2);
		iterator begin();
		iterator end();
		breadth_first_iterator breadth_first_begin(const vertex& v);
		breadth_first_iterator breadth_first_end();
		depth_first_iterator depth_first_begin(const vertex& v);
		depth_first_iterator depth_first_end(const vertex& v);
		
};
#endif
