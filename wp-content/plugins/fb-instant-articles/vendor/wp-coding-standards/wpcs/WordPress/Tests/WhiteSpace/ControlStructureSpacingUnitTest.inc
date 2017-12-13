<?php

// Bad, no space after opening control structure.
while( have_posts() ) { // Okay, comments are okay here.
	// Okay, comments are okay here as well.
} // Okay, comments are okay here.

// See https://github.com/WordPress-Coding-Standards/WordPress-Coding-Standards/issues/40 .
if ( true ) {

	// code.
} else { // Are we allowed to comment here? If not, message is wrong.
	// ...
}

// Bad.
if  ( 'update' === $option_operation['operation'] )
{
	update_option( $option_operation['option_name'], $option_operation['old_value'] );

}

// Good.
if ( 'update' === $option_operation['operation'] ) {
	update_option( $option_operation['option_name'], $option_operation['old_value'] );
}

// Bad.
if(true){}


if ( true ) {
	while ( false ) {

		echo 'OK';

	}

}

if ( false ):
else:
endif;

if ( false ) :
else :
endif;
// @codingStandardsChangeSetting WordPress.WhiteSpace.ControlStructureSpacing spaces_before_closure_open_paren 1
function($arg){} // Bad.
function ( $arg ) {
	// Ok.
}

function () {
	// Ok.
}

function something($arg){} // Bad.
function foo( $arg ) {
	// Ok.
}

function no_params() {
	// Ok.
}

function another () {} // Bad, space before open parenthesis prohibited.
function    and_another() {} // Bad, space before function name prohibited.
function
bar() {} // Bad.
function baz()     {} // Bad.
function test()
{} // Bad.

function &return_by_ref() {} // Ok.

// @codingStandardsChangeSetting WordPress.WhiteSpace.ControlStructureSpacing spaces_before_closure_open_paren 0

function() {} // Ok.
function( $arg ) {} // Ok.
function($arg){} // Bad.
function () {} // Bad.

$closureWithArgsAndVars = function( $arg1, $arg2 ) use ( $var1, $var2 ) {}; // Ok.
$closureWithArgsAndVars = function ( $arg1, $arg2 ) use ( $var1, $var2 ) {}; // Bad.

// @codingStandardsChangeSetting WordPress.WhiteSpace.ControlStructureSpacing spaces_before_closure_open_paren 1

$closureWithArgsAndVars = function ( $arg1, $arg2 ) use ( $var1, $var2 ) {}; // Ok.

$closureWithArgsAndVars = function ( $arg1, $arg2 ) use( $var1, $var2 ) {}; // Bad, no space before open parenthesis prohibited.
$closureWithArgsAndVars = function ( $arg1, $arg2 ) use  ( $var1, $var2 ) {}; // Bad, expected exactly one space before opening parenthesis.

$closureWithArgsAndVars = function ( $arg1, $arg2 ) use ( $var1, $var2 ){}; // Bad, space between closing parenthesis and control structure required.
$closureWithArgsAndVars = function ( $arg1, $arg2 ) use ( $var1, $var2 )  {}; // Bad, expected exactly one space between closing parenthesis and control structure.

$closureWithArgsAndVars = function ( $arg1, $arg2 )use ( $var1, $var2 ) {}; // Bad, expected exactly one space between closing parenthesis and control structure.
$closureWithArgsAndVars = function ( $arg1, $arg2 )  use ( $var1, $var2 ) {}; // Bad, expected exactly one space between closing parenthesis and control structure.

// Namespaces.
use Foo\Admin;

// @codingStandardsChangeSetting WordPress.WhiteSpace.ControlStructureSpacing spaces_before_closure_open_paren -1

function( $arg ) {} // Ok.
function ( $arg ) {} // Ok.

$closureWithArgsAndVars = function( $arg1, $arg2 ) use ( $var1, $var2 ) {}; // Ok.
$closureWithArgsAndVars = function ( $arg1, $arg2 ) use ( $var1, $var2 ) {}; // Ok.

/*
 * Test for bug where this sniff was triggering a "Blank line found after control structure" error
 * if there is a blank line after the last method in a class.
 *
 * Bug did not trigger when a comment was found after the closing brace of the method.
 *
 * Neither of the below examples should trigger the error.
 */
class Bar_Foo {

	function foo() {
	} // Now you won't see the bug.

}

class Foo_Bar {

	// Now you will.
	function bar() {
	}

}

// Handle try/catch statements as well.
try{ // Bad.
	// Something
} catch(Exception $e){ // Bad.
	// Something
}

// Upstream bug PEAR #20248.
// @codingStandardsChangeSetting WordPress.WhiteSpace.ControlStructureSpacing blank_line_check true
// Bad.
if ( $one ) {

}
// @codingStandardsChangeSetting WordPress.WhiteSpace.ControlStructureSpacing blank_line_check false

// Upstream bug PEAR #20247.
do {
	echo 'hi';
} while ($blah); // Bad.

// Upstream bug GH #782
// @codingStandardsChangeSetting WordPress.WhiteSpace.ControlStructureSpacing blank_line_check true
if ( $foo ) {


    /**
     * Comment
     */
    function foo() {
        // Code here
    }


    /**
     * Comment
     */
    class bar() {

    }//end class


}
// @codingStandardsChangeSetting WordPress.WhiteSpace.ControlStructureSpacing blank_line_check false

// Check for too many spaces as long as the next non-blank token is on the same line.
function test( $blah   ) {} // Bad.
function(   $bar   ) {}  // Bad.

if (    'abc' === $test ) { // Bad.
	echo 'hi';
} elseif ( false === $foo    ) { // Bad.
	echo 'bye';
}

do {
	echo 'hi';
} while (   $blah ); // Bad.

while ( $blah   ) { // Bad.
	echo 'bye bye';
}

for (   $i = 0; $i < 1; $++    ) { // Bad.
	echo 'hi';
}

foreach (   $foo as $bar   ) { // Bad.
	echo 'hi';
}

if (
	'abc' === $test
) { // Ok.
	echo 'hi';
} elseif (
	false === $foo
	&& true === $bar
) { // Ok.
	echo 'bye';
}

// Bug #976 - the case of the disappearing comment.
if ( isset( $submenu_file ) ) {
	if ( $submenu_file == $sub_item[2] ) {
		$class[] = 'current';
	}
// If plugin_page is set the parent must either match the current page or not physically exist.
// This allows plugin pages with the same hook to exist under different parents.
} else {
	$class[] = 'current';
}

// Test finding & fixing blank line after control structure.
if ( $one ) {
}
elseif ( $two ) {
}
// else if something
else if ( $three ) {
} // else do something
else {
}

do {
}
// Comment
while ( $a === $b );

if ( $foo ) {
	try {
		// Something
	} catch ( Exception $e ) {
		// Something
	}


}

if ( $foo ) {
	try {
		// Something
	} catch ( Exception $e ) {
		// Something
	}//end try/catch <- Bad: "blank line after".


}

if ( $foo ) {
	try { // Bad.
		// Something
	} catch ( Exception $e ) {
		// Something
	} // End try/catch <- Bad: "blank line after".


}