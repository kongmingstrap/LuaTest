
function Init()
	print( "Lua Init")
end

function Execute( e)
	print( "Lua Execute");
	e:test1();
	e:test2( 33);
	e:test3( "hogehoge");
	e:Set( 999);
	e:test1();
end

function Destruct()
	print( "‚»‚¤‚¢‚¦‚Î“ú–{Œê‚¢‚¯‚é‚Á‚¯")
end