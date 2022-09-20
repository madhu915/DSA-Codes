class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        Map<String,List<String>> map=new HashMap<>();
        for(String loc:paths){
            String[] terms=loc.split(" ");
            String fol=terms[0];
            for(int i=1;i<terms.length;i++){
                int ind=terms[i].indexOf('(');
                String file=terms[i].substring(0,ind);
                String content=terms[i].substring(ind+1);
                String finalPath=fol+"/"+file;
                List<String> finalList=map.getOrDefault(content,new ArrayList<>());
                finalList.add(finalPath);
                map.put(content,finalList);
            }
        }
        List<List<String>> ans=new ArrayList<>();
        for(List<String>files:map.values()){
            if(files.size()>1)
                ans.add(new ArrayList<>(files));
        }
        return ans;
    }
}