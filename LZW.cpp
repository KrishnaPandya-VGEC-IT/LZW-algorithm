/* Completely created by Krishna Pandya- 170170116023 */

// Problems with the code: use special character in place of space 
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector <int> index;
	vector <string>str;
	vector<int>encoding;
	vector<string>decoding;
	vector<int>decode_index;
	string s1;
	string decode_str;
	cout<<"\n Enter the string:";
	cin>>s1;
	int i=0,ind=1,k;
	while(i<s1.length())
	{
		int flag=0;
		for(k=0;k<str.size();k++)
		{
			string sub;
			sub+=s1.at(i);
			if(str.at(k)==sub)
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			string temp;
			temp+=s1.at(i);
			str.push_back(temp);
			index.push_back(ind);
			ind++;
		}
		i++;
	}
	for(i=0;i<str.size();i++)
	{
		for(int j=0;j<str.size()-i-1;j++)
		{
			if(str.at(j)>str.at(j+1))
			{
				string temp=str.at(j);
				str.at(j)=str.at(j+1);
				str.at(j+1)=temp;
			}
		}
	}
	i=0;
	ind=str.size()+1;	
	while(i<s1.length())
	{
		string temp;
		int flag=0,temp_index;
		for(k=0;k<index.size();k++)
		{
			string sub;
			sub=s1.substr(i,str.at(k).length());
			if(sub==str.at(k))
			{
				flag=1;
				temp_index=k+1;
			}
		}	
		if(i+str.at(temp_index-1).length()<s1.length())
		{
			encoding.push_back(temp_index);
			temp+=str.at(temp_index-1);
			temp+=s1.at(i+str.at(temp_index-1).length());
			str.push_back(temp);
		}
		else if(i+str.at(temp_index-1).length()==s1.length())
		{
			encoding.push_back(temp_index);
		}
		index.push_back(ind);	
		ind++;
		i+=str.at(temp_index-1).length();	
	}
	cout<<"\n ----STRING VECTOR-----\n";
	for(i=0;i<str.size();i++)
	{
		cout<<"\n "<<str.at(i)<<"\t "<<index.at(i);
	}
	cout<<"\n Encoding sequence->";
	for(i=0;i<encoding.size();i++)
	{
		cout<<"\t "<<encoding.at(i);	
	}	
	i=0;
	while(str.at(i).length()==1)
	{
		decoding.push_back(str.at(i));
		i++;	
	}
	i=0;
	int pointer=0;
	cout<<"\n decoding str:";
	while(i<encoding.size())
	{
		decode_str+=decoding.at(encoding.at(i)-1);
		cout<<decoding.at(encoding.at(i)-1);	
		string temp;
		int flag1=0;
		int j=0;
		if(decode_str.size()>=2)
		{
			while(flag1==0)
			{
				temp+=decode_str.at(pointer);
				pointer++;
				int flag2=0;
				for(j=0;j<decoding.size();j++)
				{
					if(temp==decoding.at(j))
					{
						flag2=1;
						break;	
					}	
				}	
				if(flag2==0)
				{
					flag1=1;
				}
			}
			decoding.push_back(temp);
			pointer--;	
			}
		i++;
	}
	return 0;
}
