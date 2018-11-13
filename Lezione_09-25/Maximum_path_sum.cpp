
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We use a recursive function that returns 2 values: the solution of the
 * problem using the actual node as root of the tree, and the longest path
 * from the actual node to a leaf.
 * The best path leaf-leaf is the maximum between the best path in left 
 * and right subtrees and the path wich pass from the actual node.
 * The best path from here to a leaf is the meximum between best paths of
 * the children added to actual node value.
 * Solution is linear both in space and time.
 * 
*/

// Return (max path leaf-leaf, max path root-leaf )
pair< int, int > recursive( struct Node *v ) {
    if( v == NULL ) return make_pair( 0, 0 );
    
    auto left = recursive( v->left), right = recursive( v->right );
    
    return make_pair( max( max( left.first, right.first ), 
                        left.second + right.second + v->data ),
                      max( left.second, right.second ) + v->data );
}

int maxPathSum(struct Node *root)
{
    return recursive( root ).first;
}
