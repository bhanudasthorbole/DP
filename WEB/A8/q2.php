<?php
interface shape
{
	public function area();
}
class rectangle implements shape
{
	public $len;
	public $bred;
	public function __construct($l,$b)
	{
		$this->len=$l;
		$this->bred=$b;
	}
	public function area()
	{
		echo "Area is rectangle:".$this->len*$this->bred."<br>";
	}
}
class square extends rectangle
{
	public $side;
	public function __construct($s)
	{
		$this->side=$s;
	}
	public function area()
	{
		echo "area is square:".$this->side*$this->side."<br>";
	}
}
class circle implements shape
{
	public $rad;
	//public $pi=3.14;
	public function __construct($r)
	{
		$this->rad=$r;
	}
	public function area()
	{
		$area=3.14*$this->rad*$this->rad;
		echo "area is circle:".$area."<br>";
	}
}
if(isset($_POST['circle']))
{
	$obj1=new circle($_POST['rad']);
	$obj1->area();
}
if(isset($_POST['rectangle']))
{
        $obj2=new rectangle($_POST['len'],$_POST['bred']);
        $obj2->area();
}
if(isset($_POST['square']))
{
        $obj3=new square($_POST['side']);
        $obj3->area();
}
?>
