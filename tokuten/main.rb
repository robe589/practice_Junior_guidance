require 'pp'

def main()
	names=['a','b','c','d','e']
	kamokuNames=['国語','数学','理科','社会','英語']
	datas=[[5,50,30,100,20],
		     [50,30,10,80,20],
			 [20,88,33,21,50],
			 [100,98,33,22,18],
			 [1,5,30,58,32]]
	#データを格納
	tokuten=Hash.new
	datas.each_with_index do |data,i|
		tokuten[names[i]]=Hash.new
		data.each_with_index do |ten,j|
			tokuten[names[i]][kamokuNames[j]]=ten;
		end
	end
	pp tokuten
	#個人ごとの5教科平均を算出
	average=Hash.new
	names.each do |name|
		average[name]=0
		tokuten[name].each_value do |tokuten|
			average[name]+=tokuten
		end
		average[name]/=kamokuNames.length.to_f
	end
	pp average
	#教科ごとの平均を算出
	subjectAvrage=Hash.new
	kamokuNames.each do |subjectName|
		subjectAvrage[subjectName]=0
		names.length.times do |i|
			subjectAvrage[subjectName]+=tokuten[names[i]][subjectName]
		end
		subjectAvrage[subjectName]/=names.length.to_f
	end
	pp subjectAvrage
end

main()
