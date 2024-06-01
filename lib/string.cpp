int lucky_num[1009];

// 特定の数字が次いつ出てくるか、配列のindexを返す。
// current_placeの次にあるtarget_numをterminal(ex.文字列の最後)まで探索する
int next_target_num_index(int current_place, int target_num, int terminal)
{
	while (current_place < terminal && lucky_num[current_place] != target_num)
	{
		current_place++;
	}
	if (current_place == terminal) return -1;
	return current_place;
}
