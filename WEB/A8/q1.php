<?php
class Book
{
	public $book_name;
	public $book_quantity;
	public $book_price;
	public $book_stock;
	public function __construct($nm,$qty,$pri,$stk)
	{
		$this->book_name=$nm;
		$this->book_quantity=$qty;
		$this->book_price=$pri;
		$this->book_stock=$stk;
	}
	public function display()
	{
		echo "Book name:".$this->book_name."<br>";
		echo "Book quantity:".$this->book_quantity."<br>";
		echo "Book price:".$this->book_price."<br>";
		echo "Book stock:".$this->book_stock."<br>";
	}

}
$obj=new Book($_POST['bname'],$_POST['bqty'],$_POST['bprice'],$_POST['bstock']);
$obj->display();
?>
