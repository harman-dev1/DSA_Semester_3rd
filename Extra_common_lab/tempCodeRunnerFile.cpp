if(balanced_factor (root) == -2 && balanced_factor(root->r_child) == 1) {
        return RLRotation(root);
    }