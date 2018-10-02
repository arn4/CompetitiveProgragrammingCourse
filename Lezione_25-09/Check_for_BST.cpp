
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We use a recursive function that returns true or false if the 
 * corrispondent subtree is a BST, the minimum and the maximum value in
 * the array. To check if a node is the root of a subtree we can simply
 * verify that: (maximum left subtree) <= (node value) <= (minimum right subtree).
 * Complexity is O( N ) in time and O( N ) in space.
 * 
*/

pair< bool, pair <int, int> > check_tree( Node* v) {
    if( v == NULL ) return make_pair( true, make_pair( INT_MAX, INT_MIN ) );
    
    
    auto left = check_tree( v->left ) , 
         right = check_tree( v->right );
         
    bool is_BST = left.first and right.first and 
                  left.second.second <= v->data and
                  right.second.first >= v->data;
    
    return make_pair( is_BST, make_pair(
                      min( left.second.first, min( right.second.first, v->data ) ),
                      max( left.second.second, max(  right.second.second, v->data ) ) ) );
}

bool isBST(Node* root) {
    return check_tree( root ).first;
}
