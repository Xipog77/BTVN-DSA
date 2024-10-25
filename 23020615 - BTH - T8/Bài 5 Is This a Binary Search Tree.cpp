/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node class is defined as follows:
    class Node {
        int data;
        Node left;
        Node right;
     }
*/
    List<Integer> duyetcay(Node root, List<Integer> list) {
        if (root.left != null) {
            list = duyetcay(root.left,list);
        }
        list.add(root.data);
        if (root.right != null) {
            list = duyetcay(root.right,list);
        }
        return list;
    }

    boolean checkBST(Node root) {
        List<Integer> list = new ArrayList<>();
        list = duyetcay(root,list);
        
        for (int i = 1; i < list.size(); i++) {
            if (list.get(i) <= list.get(i-1)) return false;
        }
        
        return true;
        
    }