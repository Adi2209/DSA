<h2><a href="https://leetcode.com/problems/compare-version-numbers/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Amazon</div><div class="companyTagsContainer--tagOccurence">7</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Microsoft</div><div class="companyTagsContainer--tagOccurence">4</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Arista Networks</div><div class="companyTagsContainer--tagOccurence">2</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Nutanix</div><div class="companyTagsContainer--tagOccurence">2</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>165. Compare Version Numbers</a></h2><h3>Medium</h3><hr><div><p>Given two version numbers,&nbsp;<code>version1</code> and <code>version2</code>, compare them.</p>

<ul>
</ul>

<p>Version numbers consist of <strong>one or more revisions</strong> joined by a dot&nbsp;<code>'.'</code>. Each revision&nbsp;consists of <strong>digits</strong>&nbsp;and may contain leading <strong>zeros</strong>. Every revision contains <strong>at least one character</strong>. Revisions are <strong>0-indexed from left to right</strong>, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example&nbsp;<code>2.5.33</code>&nbsp;and&nbsp;<code>0.1</code>&nbsp;are valid version numbers.</p>

<p>To compare version numbers, compare their revisions in <strong>left-to-right order</strong>. Revisions are compared using their&nbsp;<strong>integer value ignoring any leading zeros</strong>. This means that revisions&nbsp;<code>1</code>&nbsp;and&nbsp;<code>001</code>&nbsp;are considered&nbsp;<strong>equal</strong>. If a version number does not specify a revision at an index, then&nbsp;<strong>treat the revision as&nbsp;<code>0</code></strong>. For example, version&nbsp;<code>1.0</code> is less than version&nbsp;<code>1.1</code>&nbsp;because their revision 0s are the same, but their revision 1s are&nbsp;<code>0</code>&nbsp;and&nbsp;<code>1</code>&nbsp;respectively, and&nbsp;<code>0 &lt; 1</code>.</p>

<p><em>Return the following:</em></p>

<ul>
	<li>If <code>version1 &lt; version2</code>, return <code>-1</code>.</li>
	<li>If <code>version1 &gt; version2</code>, return <code>1</code>.</li>
	<li>Otherwise, return <code>0</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> version1 = "1.01", version2 = "1.001"
<strong>Output:</strong> 0
<strong>Explanation:</strong> Ignoring leading zeroes, both "01" and "001" represent the same integer "1".
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> version1 = "1.0", version2 = "1.0.0"
<strong>Output:</strong> 0
<strong>Explanation:</strong> version1 does not specify revision 2, which means it is treated as "0".
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> version1 = "0.1", version2 = "1.1"
<strong>Output:</strong> -1
<strong>Explanation:</strong> version1's revision 0 is "0", while version2's revision 0 is "1". 0 &lt; 1, so version1 &lt; version2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= version1.length, version2.length &lt;= 500</code></li>
	<li><code>version1</code> and <code>version2</code>&nbsp;only contain digits and <code>'.'</code>.</li>
	<li><code>version1</code> and <code>version2</code>&nbsp;<strong>are valid version numbers</strong>.</li>
	<li>All the given revisions in&nbsp;<code>version1</code> and <code>version2</code>&nbsp;can be stored in&nbsp;a&nbsp;<strong>32-bit integer</strong>.</li>
</ul>
</div>