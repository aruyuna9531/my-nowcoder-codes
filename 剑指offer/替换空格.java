//Java
//��Ŀ��ʵ�ֺ������ַ���str�еĿո��滻Ϊ"%20"

//˼·��str�������ֿո�ʱ����%20���������ԭ�ַ�
public class Solution {
    public String replaceSpace(StringBuffer str) 
    {
    	StringBuffer s = new StringBuffer();
    	for(int i=0;i<str.length();i++){
    		if(str.charAt(i)==' ')s.append("%20");
    		else s.append(str.charAt(i));
    	}
    	return s.toString();
    }
}