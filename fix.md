## 変更箇所

- add .gitignore

- fix Makefile
	- 	linux版対応

- fix header file
	- linux版, cluster版両対応
	- いらない関数削除, 並び替え
- fix put_err(const char *str)


## 直すところ

### map check
- 直すべき
	- map_yshimod/f_map01
		- ２つのEが一列にある
	- map_yshimod/f_map11
		- 壁に囲まれていないのに表示できている
	- map_yshimod/f_map12
		- 壁に囲まれていないのに表示できている
	- map_yshimod/f_map13
		- 壁に囲まれていないのに表示できている
	- map_yshimod/f_map14
		- 壁に囲まれていないのに表示できている
	- map_yshimod/f_map21
		- ゴールできる道がない
- どちらでも良いかも
	- map_yshimod/f_map22
		- cが集められない
	- map_yshimod/f_map23
		- cが集められない
	- map_yshimoda/t_map08
		- 0がないマップがエラーになる

### mlx
- wasd, 方向キー以外を押しても、stepが増えてしまう
- バツボタンが反応しなかった
- 巨大なマップでsegvが起こる
	- t_map05