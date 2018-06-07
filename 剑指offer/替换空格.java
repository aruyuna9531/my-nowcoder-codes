//Java
//题目：实现函数将字符串str中的空格替换为"%20"

//思路：str检索出现空格时加入%20，否则加入原字符
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