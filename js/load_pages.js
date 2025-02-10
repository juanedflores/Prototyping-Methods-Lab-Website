function load_syllabus() {
  var html = `
  <object data="PML_Syllabus_2025.pdf" type="application/pdf" width="100%" height="1000" title="Embedded PDF Viewer">
    <p>
      Your browser does not support PDFs.
      <a href="document.pdf">Download the PDF</a>
    </p>
  </object>
  `;

  $('#right-col').html(html);
}

function load_materials() {
  var html = `
  <div style="padding: 20px;">
    <h3>Material Gathering</h3>
    <ul>
      <li>
        <a href="https://www.servocity.com/">Servocity</a>
      </li>
      <li>
        <a href="https://openbuildspartstore.com/">Openbuilds</a>
      </li>
      <li>
        <a href="https://www.mcmaster.com/products/power-transmission/">Mcmaster-Carr: Power Transmission</a>
      </li>
      <li>
        <a href="https://www.sparkfun.com/categories/31">Sparkfun: Robotics</a>
      </li>
      <li>
        <a href="https://www.vexrobotics.com/catalogsearch/result/?q=__empty__&vex_product_type=Motion&vex_site=product_hits&zendesk_vexroboticshelp_articles%5BrefinementList%5D%5Blocale.name%5D%5B0%5D=English">Vexrobotics</a>
      </li>
    </ul>
  </div>
  `;

  $('#right-col').html(html);
}

function load_resources() {
  var html = `
  <div style="padding: 20px;">
  <h3>Useful Resources</h3>
    <h4>Online Complimentary Learning Material</h4>
    <h5>Electronics / Programming</h5>
    <ul>
      <li>
        <a href="https://makeabilitylab.github.io/physcomp/">makeabilitylab</a>
      </li>
      <li>
        <a href="https://itp.nyu.edu/physcomp/introduction-to-the-nano-33-iot/">ITP Physical Computing Course with Arduino Nano 33 IoT</a>
      </li>
    </ul>
    <h6>Design</h6>
    <ul>
      <li><a href="https://www.interaction-design.org/literature/book/the-glossary-of-human-computer-interaction">The Glossary of Key Terms in Human-Computer Interaction</a></li>
    </ul>
    <h4>Modern, Contemporary and Media Art History + Databases</h4>
    <ul>
      <li>
        <a href="https://smarthistory.org/">SmArtHistory</a>
      </li>
      <li>
        <a href="https://www.ubu.com/">UbuWeb</a>
      </li>
      <li>
        <a href="http://www.mediaartnet.org/">Media Art Net</a>
      </li>
      <li>
        <a href="https://artelectronicmedia.com/en/">Art and Electronic Media</a>
      </li>
      <li>
        <a href="https://channel.louisiana.dk/topics/art">Louisiana Channel</a>
      </li>
      <li>
        <a href="https://www.vdb.org/">Video Data Bank</a>
      </li>
    </ul>
    <h4>Books / Magazines / Blogs:</h4>
    <ul>
      <li>
        <a href="https://cabaret.co.uk/product/cabaret-mechanical-movement/">Book: Cabaret Mechanical Movement</a>
      </li>
      <li>
        <a href="https://rhizome.org/">Rhizome</a>
      </li>
    </ul>
  </div>
  `;

  $('#right-col').html(html);
}

function week1() {
  var html = `
      <section class="slides_section">
        <embed type="text/html" src="weeks/week_1_day1/index.html" width="100%" height="500px" style="border: solid black 1px" />
      </section>
      <div style="padding-left:30px; padding-right:30px" uk-card>
        <h3>Agenda</h3>
        <ul>
          <li>Introductions ( Who are you? Who am I? )</li>
          <li>Overview of the Course ( What the class is, and what it is not )</li>
          <li>Getting Setup: ( Classroom, Deciding when to Meet )</li>
          <li>The Plan in the Coming Weeks ( Buy Materials, Workshops )</li>
          <li>The Design of Everyday Things ( Analyzing the interaction designs of examples found in the building )</li>
        </ul>
      </div>
  `;

  $('#right-col').html(html);
}

function week2() {
  var html = `
      <section class="slides_section">
        <embed type="text/html" src="weeks/week2/index.html" width="100%" height="500px"
          style="border: solid black 1px" />
      </section>
      <div style="padding-left:30px; padding-right:30px" uk-card>
        <h3>Agenda</h3>
        <ul>
          <li>Housekeeping: materials and classroom</li>
          <li>Discussion - Reading of "The Design of Everyday Things"</li>
          <li>See and talk about real examples (Products, Art)</li>
          <li>Example Arduino Projects</li>
          <li>Intro to Electronics with TinkerCAD</li>
        </ul>
      </div>
  `;

  $('#right-col').html(html);
}

function week3() {
  var html = `
      <section class="slides_section">
        <embed type="text/html" src="slides/week3/index.html" width="100%" height="500px"
          style="border: solid black 1px" />
      </section>
      <div style="padding-left:30px; padding-right:30px" uk-card>
      <a href="./slides/week3/index.html">
      Open Slides in New Tab
      </a>
        <h3>Agenda</h3>
        <ul>
          <li>Check In</li>
          <li>Show the Circuit in TinkerCad</li>
          <li>Talk about the Soldering Kits</li>
          <li>Introduce Soldering Resources and Tips</li>
          <li>Demonstration</li>
        </ul>
      </div>
      <div style="padding-top: 50px;"></div>
  `;

  $('#right-col').html(html);
}
