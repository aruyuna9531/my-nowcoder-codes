//Java
//输入二叉树前序、中序遍历结果构建这棵二叉树（不含重复数字）

//思路：
//①前序第1个元素是头结点
//②找到头结点元素在中序遍历中的位置x，中序序列0~x-1是左子树元素中序序列，前序序列1~x是左子树前序序列
//③前序序列x+1~end是右子树前序序列，中序序列x+1~end是右子树中序序列
//④左子树和右子树也利用各前中序序列根据①~③构建二叉树
//⑤构建完毕返回头结点
public class Solution {
    public TreeNode reConstructBinaryTree(int [] pre,int [] in) {
        TreeNode root=new TreeNode(pre[0]);
        int i;
        int top=pre[0];
        for(i=0;i<pre.length;i++){
        	if(in[i]==top)break;
        }
        if(i>0){
        	int []nextLeftPre=new int[i];
        	int []nextLeftIn=new int[i];
        	for(int j=0;j<i;j++){
        		nextLeftPre[j]=pre[j+1];
        		nextLeftIn[j]=in[j];
        	}
        	root.left=reConstructBinaryTree(nextLeftPre,nextLeftIn);
        	
        }
        //else Left Child is Null
        if(pre.length-i-1>0){
        	int []nextRightPre=new int[pre.length-i-1];
        	int []nextRightIn=new int[pre.length-i-1];
        	for(int j=i+1;j<pre.length;j++){
        		nextRightPre[j-i-1]=pre[j];
        		nextRightIn[j-i-1]=in[j];
        	}
        	root.right=reConstructBinaryTree(nextRightPre,nextRightIn);
        }
        return root;
    }
}