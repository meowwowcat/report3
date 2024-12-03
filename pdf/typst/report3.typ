#set text(font : "HackGen")

#import "@preview/codelst:2.0.2": sourcecode
#import "@preview/codelst:2.0.2": sourcefile, 

#align(center)[コンピュータ実験レポート２]
#align(right)[24cb062h 菅原明]

すべてのファイルを https://github.com/meowwowcat/report3.git に置きました．

= 課題 20

== 方法



#sourcefile(read("20.c"), file:"20.c")

$3~10$行目で文字の定義をする．16行目から22行目で課題16のファイルの読み込み．31行目で導関数を数値で計算．
34行目のcalc_chi2で関数を計算．差分をとって近似．
38行目から45行目で関数を計算．48以降で具体的な関数を定義．

== 結果

#read("output1.txt")

== 考察
課題16における$v_0$にだいたい等しい．したがってこの値は妥当である．

= 課題 21

== 方法

#sourcefile(read("21.c"), file:"21.c")

最小二乗法の計算に用いる色々な和の計算をする．．


== 結果

#read("out2.txt")

== 考察
課題16で用いた，$v_x,x_0$の値とだいたい等しい．
したがってこの値は妥当である．