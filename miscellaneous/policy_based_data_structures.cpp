#if      __cplusplus >= 201402L
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#endif

#if   __cplusplus >= 201402L
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#endif

template <class T, typename Comp = less <T> >
using indexed_set = tree <T, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>;

template <typename K, typename V, typename Comp = less <K>>
using indexed_map = tree <K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;

