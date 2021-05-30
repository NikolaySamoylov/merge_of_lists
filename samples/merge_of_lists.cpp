// Слияние двух отсортированных списков
template <class T>
void merge(List<T>& l1, List<T>& l2, List<T>& res)
{
	if (l1.empty())
		res = l2;
	if (l2.empty())
		res = l1;
	if (l1.empty() && l2.empty())
		throw "Lists are empty!";
	List<T>::Iterator i = l1.begin();
	List<T>::Iterator j = l2.begin();
	List<T>::Iterator k = res.begin();
	if (k != NULL)
		while (k->pNext != NULL)
			k = k->pNext;
	while (i != l1.end() && j != l2.end())
		if (i->data < j->data)
		{
			res.insert(*k, (i++)->data);
			if (k != NULL)
				k++;
			else
				k = res.begin();
		}
		else
		{
			res.insert(*k, (j++)->data);
			if (k != NULL)
				k++;
			else
				k = res.begin();
		}
	while (i != l1.end())
	{
		res.insert(*k, (i++)->data);
		k++;
	}
	while (j != l2.end())
	{
		res.insert(*k, (j++)->data);
		k++;
	}
}