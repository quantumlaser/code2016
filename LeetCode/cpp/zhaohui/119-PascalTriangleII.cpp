class Solution {
public:
	vector<int> getRow(int rowIndex) {
        if(rowIndex ==0){
			vector<int> row(1,1);
			return row;
		}
		vector<int> pRow = getRow(rowIndex-1);
		int temp = pRow[0],temp1=0;
		for(int i=1;i<rowIndex;i++){
			temp1 = pRow[i];
			pRow[i] = temp + pRow[i];
			temp = temp1;
		}
		pRow.push_back(1);
		return pRow;	
    }
};