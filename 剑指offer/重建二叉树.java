//Java
//���������ǰ������������������ö������������ظ����֣�

//˼·��
//��ǰ���1��Ԫ����ͷ���
//���ҵ�ͷ���Ԫ������������е�λ��x����������0~x-1��������Ԫ���������У�ǰ������1~x��������ǰ������
//��ǰ������x+1~end��������ǰ�����У���������x+1~end����������������
//����������������Ҳ���ø�ǰ�������и��ݢ�~�۹���������
//�ݹ�����Ϸ���ͷ���
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